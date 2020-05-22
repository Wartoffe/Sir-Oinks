#ifndef SIR_OINKS_HPP_INCLUDED
#define SIR_OINKS_HPP_INCLUDED
#include <windows.h>
#include "Pozicija.hpp"

class Sir_Oinks
{
private:

    double v;
    bool gr;
    bool hat;
    bool clinging;
    Pozicija Sirp;
    double vMax;

public:

    Sir_Oinks(double v1,bool gr1,bool hat1,bool clinging1,int xx,int yy,double vMax1):Sirp(xx,yy)
    {
        v=v1;
        gr=gr1;
        hat=hat1;
        clinging=clinging1;
        vMax=vMax1;
    }

    void Jump()
    {
        if(gr==true)
        {

          int ytemp=Sirp.Gety();
            ytemp+=3;
            Sirp.Sety(ytemp);

            gr=false;

            Sleep(1000);

            ytemp-=3;
            Sirp.Sety(ytemp);
            gr=true;
        }
    }

    void Wmove()
    {
        Sirp.Yup();
    }

    void Amove()
    {
        Sirp.Xleft();
    }

    void Smove()
    {
        Sirp.Ydown();
    }

    void Dmove()
    {
        Sirp.Xright();
    }


    //Simulacija skoka
    int Getx()
    {
        int xpom=Sirp.Getx();
        return xpom;
    }

    int Gety()
    {
        int ypom=Sirp.Gety();
        return ypom;
    }
};

#endif // SIR_OINKS_HPP_INCLUDED
