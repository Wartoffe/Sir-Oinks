#ifndef TROFEJ_HPP_INCLUDED
#define TROFEJ_HPP_INCLUDED

#include "Pozicija.hpp"
#include "Sir_Oinks.hpp"
#include "Korisnik.hpp"

class Trofej
{
private:

    int points;
    Pozicija ptrof;
    bool prisutan;

public:

    Trofej(int points1,bool prisutan1,int xx,int yy):ptrof(xx,yy)
    {
            points=points1;
            prisutan=prisutan1;
    }


};

#endif // TROFEJ_HPP_INCLUDED
