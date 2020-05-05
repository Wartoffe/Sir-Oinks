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

    Pozicija p(5,7);
    Dijalog d1("Dijalog.txt",0);
    Izazov c1(0,1000,"Wartoffe",4,0,0,0,6,8);
    Korisnik user1(200,27,1,"Wartoffe");
    Level lvl1(1,7,8,0,0,1,0,8,9,20,"Grass",30,0,0,0,19,13,0);
    Prodavac prodava1("Dijalog.txt",0,200,20,20,0);
    Sir_Oinks sir(2,1,0,0,0,0,20);
    Scena s1(10,8);
    Trofej trofi1(100,1,8,7);
    Turf turfi1("Thiccice",4,1,1,0,7,16);

    citajTxt("Turf.txt.txt");


}
