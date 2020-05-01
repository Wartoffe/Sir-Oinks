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

    Trofej(int points,bool prisutan,int xx,int yy,):ptrof(xx,yy)


};

#endif // TROFEJ_HPP_INCLUDED
