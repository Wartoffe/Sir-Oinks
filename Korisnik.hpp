#ifndef KORISNIK_HPP_INCLUDED
#define KORISNIK_HPP_INCLUDED
#include <vector>
#include <fstream>
using namespace std;

class Korisnik
{
protected:

    int hs;
    int time;
    int levelnum;
    string ime;

    static int usersnum;
    int id;

public:




    Korisnik(string ime1,int id1,int hs1=0,int time1=0,int levelnum1=1)
    {
        hs=hs1;
        time=time1;
        levelnum=levelnum1;
        ime=ime1;
        id=id1;
        usersnum++;


    }

    string getIme()
    {
        return ime;
    }


    void about()
    {
        cout<<ime<<","<<id<<endl;

    }

    int getid()
    {
        return id;
    }

    int getNumofusers()
    {
        return usersnum;
    }


    void Pointup(int pup)
    {
        hs+=pup;
    }
    friend ostream& operator<<(ostream& izlaz, const Korisnik& k);


    void Winpoints()
    {
        hs+=200;
    }

    void Scoreispis()
    {
        cout<<hs<<endl;
    }

    int Scoreget()
    {
        return hs;
    }

};




#endif // KORISNIK_HPP_INCLUDED
