
#define PORTF_BASE 0x6A0
#define PORTF_DIRSET (*((volatile unsigned char *)(PORTF_BASE+0x01)))
#define PORTF_OUT (*((volatile unsigned char *)(PORTF_BASE+0x04)))
#define PORTF_OUTSET (*((volatile unsigned char *)(PORTF_BASE+0x05)))
#define PORTF_OUTCLR (*((volatile unsigned char *)(PORTF_BASE+0x06)))
#define UARTF0_BASE 0xBA0
#define UARTF0_DATA (*((volatile unsigned char *)(UARTF0_BASE+0x00)))
#define UARTF0_STATUS (*((volatile unsigned char *)(UARTF0_BASE+0x01)))
#define UARTF0_CTRLB (*((volatile unsigned char *)(UARTF0_BASE+0x04)))
#define UARTF0_CTRLC (*((volatile unsigned char *)(UARTF0_BASE+0x05)))
#define UARTF0_BAUDCTRLA (*((volatile unsigned char *)(UARTF0_BASE+0x06)))
#define UARTF0_BAUDCTRLB (*((volatile unsigned char *)(UARTF0_BASE+0x07)))

#define UARTF1_BASE 0xBB0
#define UARTF1_DATA (*((volatile unsigned char *)(UARTF1_BASE+0x00)))
#define UARTF1_STATUS (*((volatile unsigned char *)(UARTF1_BASE+0x01)))
#define UARTF1_CTRLB (*((volatile unsigned char *)(UARTF1_BASE+0x04)))
#define UARTF1_CTRLC (*((volatile unsigned char *)(UARTF1_BASE+0x05)))
#define UARTF1_BAUDCTRLA (*((volatile unsigned char *)(UARTF1_BASE+0x06)))
#define UARTF1_BAUDCTRLB (*((volatile unsigned char *)(UARTF1_BASE+0x07)))

void dummy ( void );

void uart_putc ( unsigned char x )
{
    while((UARTF0_STATUS&(1<<5))==0) continue;
    UARTF0_DATA=x;
}

void hexstring ( unsigned int d )
{
    //unsigned int ra;
    unsigned int rb;
    unsigned int rc;

    rb=16;
    while(1)
    {
        rb-=4;
        rc=(d>>rb)&0xF;
        if(rc>9) rc+=0x37; else rc+=0x30;
        uart_putc(rc);
        if(rb==0) break;
    }
    uart_putc(0x0D);
    uart_putc(0x0A);
}

void notmain ( void )
{
    unsigned int ra;

    //setup GPIOF7 for led output
    PORTF_DIRSET=1<<7;
    PORTF_OUTSET=1<<7;

    //initialize uartf0 TX0 on GPIOF3
    PORTF_DIRSET=1<<3;
    PORTF_OUTSET=1<<3;
    UARTF0_CTRLC=0x03;
    UARTF0_BAUDCTRLA=16;
    UARTF0_BAUDCTRLB=0;
    UARTF0_CTRLB=1<<3;

    while(1)
    {
        for(ra=0x3000;ra;ra--) dummy();
        PORTF_OUTCLR=0x80;
        //uart_putc(0x55);
        hexstring(0x1234);
        for(ra=0x3000;ra;ra--) dummy();
        PORTF_OUTSET=0x80;
        //uart_putc(0x56);
        hexstring(0xABCD);
    }
}
