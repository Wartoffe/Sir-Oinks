#ifndef TURF_HPP_INCLUDED
#define TURF_HPP_INCLUDED

#include "Pozicija.hpp"

using namespace std;

class Turf
{
protected:

    string ime;
    double maxv;
    bool bouncy;
    bool slip;
    bool sharp;
    Pozicija pturf;

public:

    Turf(string ime1, double maxv1, bool bouncy1, bool slip1, bool sharp1, int xx, int yy): pturf(xx,yy)

        ime=ime1;
        maxv=maxv1;
        bouncy=bouncy1;
        slip=slip1;
        sharp=sharp1;

    };

class Meanturf: public Turf;
{
private:
    bool hinder;
public:
    Meanturf(string ime1, double maxv1, bool bouncy1, bool slip1, bool sharp1, int xx, int yy, bool hinder1): Turf(ime1,maxv1,bouncy1,slip1,sharp1,xx,yy), hinder(hinder1)
    {

    }

};

#endif // TURF_HPP_INCLUDED
