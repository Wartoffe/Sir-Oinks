#include <iostream>
#include "Sir_Oinks.hpp"
#include "Pozicija.hpp"
#include "Dijalog.hpp"
#include "Izazov.hpp"
#include "Korisnik.hpp"
#include "Level.hpp"
#include "Prodavac.hpp"
#include "Scena.hpp"
#include "Trofej.hpp"
#include "Turf.hpp"
#include <fstream>
using namespace std;

ostream& operator<<(ostream& izlaz, const Turf& t){
    izlaz<<"Turf"<<endl;
    izlaz<<"ime :"<<t.ime<<endl;
    izlaz<<"maxv :"<<t.maxv<<endl;
    izlaz<<"bouncy : "<<t.bouncy<<endl;
    izlaz<<"slip :"<<t.slip<<endl;
    izlaz<<"sharp :"<<t.sharp<<endl;
    izlaz<<"pturf : "<<t.pturf<<endl;

    return izlaz;

}
ostream& operator<<(ostream& izlaz, const Trofej& tro)
{
    izlaz<<"Trofej"<<endl;
    izlaz<<"pojeni :"<<tro.points<<endl;
    izlaz<<"pozicija trofeja :"<<tro.ptrof<<endl;
    izlaz<<"da li postoji trofej :"<<tro.prisutan<<endl;

    izlaz<<endl;

    return izlaz;
}

ostream& operator<<(ostream& izlaz, const Pozicija& p){
    izlaz<<"pozicija"<<endl;
    izlaz<<"x :"<<p.x<<endl;
    izlaz<<"y :"<<p.y<<endl;
    izlaz<<endl;

    return izlaz;

}




ostream& operator<<(ostream& izlaz, const Korisnik& k){
    izlaz<<"Korisnik"<<endl;
    izlaz<<"highscore :"<<k.hs<<endl;
    izlaz<<"playtime :"<<k.time<<endl;
    izlaz<<"level :"<<k.levelnum<<endl;
    izlaz<<"username :"<<k.ime<<endl;
    izlaz<<endl;

    return izlaz;

}

int Korisnik::usersnum=0;

void citajTxt(string turf)
{
    string linija;
    ifstream fajl (turf);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            cout << linija << '\n';
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";

}



int main()
{

    /*Pozicija p1(5,7);
    Dijalog d1("Dijalog.txt",0);
    Izazov c1(0,1000,"Wartoffe",4,0,0,0,6,8);
    Korisnik user1(200,27,1,"Wartoffe");
    Level lvl1(1,7,8,0,0,1,0,8,9,20,"Grass",30,0,0,0,19,13,0);
    Prodavac prodava1("Dijalog.txt",0,200,20,20,0);
    Sir_Oinks sir(2,1,0,0,0,0,20);
    Scena s1(10,8);*/
    Trofej trofi1("Yay",100,1,8,7);
    Aht trofi2("Nay",200,1,9,1);
    Aht trofi3("Meh",180,1,6,4);
    /*Turf t("Thiccice",4,1,1,0,7,16);
    cout<<t;
    citajTxt("Turf.txt.txt");
    cout<<user1;
    cout<<trofi1;
    cout<<user1.getNumofusers();*/
    Achivements a;
    a.dodaj(&trofi1);
    a.dodaj(&trofi2);
    a.dodaj(&trofi3);
    //a.ispisiArhive();-ispis
    a.Searchfor();//ovo je otprilike search/filter(radi)

    a.Kill(trofi2);//-brisanje
    //a.ispisiArhive();
}
