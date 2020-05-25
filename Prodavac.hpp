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
    Prodavac(string di,int k,int cena1,int Max,int cnum,int p=200):d1(di,k)
    {
        cena=cena1;
        Maxbi=Max;
        tbi=cnum;
        pare=p;
    }

    int Getpare()
    {
        return pare;
    }

    void Kupovanje(int brojitema,int pare)
    {
        if((pare-(brojitema*cena)>=0)&& tbi>=brojitema)
        {

            tbi-=brojitema;
            Maxbi+=brojitema;
            cena-=(brojitema*cena)/20;
            pare-=brojitema*cena;
            Setpare(pare);
            cout<<"Purches succusess"<<endl;
            d1.Saysomethingiamgivinguponyou();

        }
        else
            cout<<"Invalid";
        //simulacija prave radnje sto vise kupujes to vise mozes sledeci put i to vise favorizuje prodavac
    }

    void Setpare(int pare1)
    {
        pare=pare1;
    }


};


#endif // PRODAVAC_HPP_INCLUDED
