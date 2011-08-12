
extern void PUT8 ( unsigned int, unsigned int );
extern unsigned int GET8 ( unsigned int );
extern void dummy ( void );

void dowait ( void )
{
    unsigned int ra;

    ra=0x20000;
    while(ra--) dummy();
}

void notmain ( void )
{
    unsigned int ra,rb,rc,rd,re,rf;

    ra=GET8(0x2009C022);
    ra|=0xB4;
    PUT8(0x2009C022,ra);


    ra=0x2009C03A;
    rb=0x2009C03E;
    rc=0x80;
    rd=0x20;
    re=0x10;
    rf=0x04;

    while(1)
    {
        PUT8(ra,rc);
        PUT8(rb,rd);
        PUT8(rb,re);
        PUT8(rb,rf);
        dowait();
        PUT8(rb,rc);
        PUT8(ra,rd);
        PUT8(rb,re);
        PUT8(rb,rf);
        dowait();
        PUT8(rb,rc);
        PUT8(rb,rd);
        PUT8(ra,re);
        PUT8(rb,rf);
        dowait();
        PUT8(rb,rc);
        PUT8(rb,rd);
        PUT8(rb,re);
        PUT8(ra,rf);
        dowait();
        PUT8(rb,rc);
        PUT8(rb,rd);
        PUT8(ra,re);
        PUT8(rb,rf);
        dowait();
        PUT8(rb,rc);
        PUT8(ra,rd);
        PUT8(rb,re);
        PUT8(rb,rf);
        dowait();
    }

    //while(1)
    //{
        //PUT8(0x2009C03A,0x80);
        //PUT8(0x2009C03E,0x20);
        //PUT8(0x2009C03E,0x10);
        //PUT8(0x2009C03E,0x04);
        //dowait();
        //PUT8(0x2009C03E,0x80);
        //PUT8(0x2009C03A,0x20);
        //PUT8(0x2009C03E,0x10);
        //PUT8(0x2009C03E,0x04);
        //dowait();
        //PUT8(0x2009C03E,0x80);
        //PUT8(0x2009C03E,0x20);
        //PUT8(0x2009C03A,0x10);
        //PUT8(0x2009C03E,0x04);
        //dowait();
        //PUT8(0x2009C03E,0x80);
        //PUT8(0x2009C03E,0x20);
        //PUT8(0x2009C03E,0x10);
        //PUT8(0x2009C03A,0x04);
        //dowait();
        //PUT8(0x2009C03E,0x80);
        //PUT8(0x2009C03E,0x20);
        //PUT8(0x2009C03A,0x10);
        //PUT8(0x2009C03E,0x04);
        //dowait();
        //PUT8(0x2009C03E,0x80);
        //PUT8(0x2009C03A,0x20);
        //PUT8(0x2009C03E,0x10);
        //PUT8(0x2009C03E,0x04);
        //dowait();
    //}


}

