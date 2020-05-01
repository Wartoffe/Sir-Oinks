#ifndef PRODAVAC_HPP_INCLUDED
#define PRODAVAC_HPP_INCLUDED

#include "Dijalog.hpp""

class Prodavac
{
private:

    Dijalog d1;
    int cena;
    int Maxbi;//maksimalni broj itema
    int tbi;//trenutni broj itema
    int pare;

public:
    Prodavac(string di,int k,int cena1,int Max,int cnum,int p):d1(di,k)
    {
        cena=cena1;
        int Maxbi=Max;
        int tbi=cnum;
        int pare=p;
    }

    void Kupovanje(int brojitema,int pare)
    {
        if((pare-(brojitema*cena)>=0)&& tbi>=brojitema)
        {

            tbi-=brojitema;
            Maxbi+=brojitema;
            cena-=(brojitema*cena)/20;
            pare-=brojitema*cena;

        }
        //simulacija prave radnje sto vise kupujes to vise mozes sledeci put i to vise favorizuje prodavac
    }


};


#endif // PRODAVAC_HPP_INCLUDED
