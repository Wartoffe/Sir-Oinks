#ifndef IZAZOV_HPP_INCLUDED
#define IZAZOV_HPP_INCLUDED

#include "Turf.hpp"

class Izazov
{
private:

    bool predjenaigrica;
    int hs;
    Turf turfc;
public:

    Izazov(bool predjenaigrica1,int hs1,string ime1,double maxv1,bool bouncy1,bool slip1,bool sharp1, int xx, int yy):turfc(ime1,maxv1,bouncy1,slip1,sharp1,xx,yy){

        hs=hs1;
        predjenaigrica=predjenaigrica1;

    }
};

#endif // IZAZOV_HPP_INCLUDED
