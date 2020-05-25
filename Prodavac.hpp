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

public:
    Prodavac(string di,int k,int cena1,int Max,int cnum):d1(di,k)
    {
        cena=cena1;
        Maxbi=Max;
        tbi=cnum;

    }



    void Kupovanje(int brojitema,int pare1,Korisnik* k)
    {
        if((pare1-(brojitema*cena)>=0)&& tbi>=brojitema)
        {

            tbi-=brojitema;
            Maxbi+=brojitema;
            cena-=(brojitema*cena)/20;
            pare1=brojitema*cena;
            k->Setpare(pare1);
            k->about();
            cout<<"Purches succusess"<<endl;
            d1.Saysomethingiamgivinguponyou();

        }
        else
            cout<<"Invalid";
        //simulacija prave radnje sto vise kupujes to vise mozes sledeci put i to vise favorizuje prodavac
    }




};


#endif // PRODAVAC_HPP_INCLUDED
