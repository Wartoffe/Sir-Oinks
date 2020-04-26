#ifndef SIR_OINKS_HPP_INCLUDED
#define SIR_OINKS_HPP_INCLUDED

#include "Pozicija.hpp"

class Sir_Oinks
{
private:

    double v;
    bool gr;
    bool hat;
    bool clinging;
    class Pozicija;
    double vMax;

public:

    Jump()
    {
        if(gr=true)
        {
            SirO.Pozicija(x,y+3);
        }
    }
    Sprint()
    {
        if(v<vMax)
        {
            v=vMax;
        }
    }

};

#endif // SIR_OINKS_HPP_INCLUDED
