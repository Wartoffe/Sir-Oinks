#ifndef TROFEJ_HPP_INCLUDED
#define TROFEJ_HPP_INCLUDED

#include <vector>
#include "Pozicija.hpp"
#include "Sir_Oinks.hpp"
#include "Korisnik.hpp"

using namespace std;

class Trofej
{
protected:

    string ime;
    int points;
    Pozicija ptrof;
    bool prisutan;

public:

    Trofej(string ime1,int points1,bool prisutan1,int xx,int yy):ptrof(xx,yy)
    {
            ime=ime1;
            points=points1;
            prisutan=prisutan1;
    }

    virtual void statb()
    {
        cout<<ime<<endl;
        cout<<points<<endl;
        cout<<prisutan<<endl;
        cout<<endl;
    }

    virtual void pickup()
    {
        if(prisutan)
        {
            prisutan=0;
        }

    }

    virtual int id()
    {
        return 0;
    }

    int getPoints() const
    {
        return points;
    }

    string getName() const
    {
        return ime;
    }
    friend ostream& operator<<(ostream& izlaz, const Trofej& tro);
};

class Aht : public Trofej
{
public:

    Aht(string ime1,int points1,bool prisutan1,int xx,int yy):Trofej(ime1,points1,prisutan1,xx,yy)
    {

    }

    void pickup()
    {
        if(prisutan && points==0)
        {
            prisutan=0;

        }
        else
            points-=5;
    }
    void statb()
    {
        Trofej::statb();
        cout<<">: D"<<endl;
        cout<<endl;
    }

    int id()
    {
        return 1;
    }

};


class Achivements
{
private:
    vector <Trofej*> achiv;
public:
    void dodaj(Trofej* t){
        achiv.push_back(t);

    }

    void ispisiArhive(){
        cout<<"Lista Trofeja: "<<endl;

        for (auto it=achiv.begin(); it<achiv.end(); it++){
            (*it)->statb();

        }
    }

    void Searchfor(){
        cout<<"0-za obicne "<<endl<<"1-za egzoticne"<<endl;
        int x;
        cin>>x;

        for (auto it=achiv.begin(); it<achiv.end(); it++){
                if ((*it)->id()==x)
                    (*it)->statb();

        }
    }

    void Kill(const Trofej& t){
        for (auto it=achiv.begin(); it<achiv.end(); it++){
            if (t.getName()==(*it)->getName() && t.getPoints()==(*it)->getPoints()){
                achiv.erase(it);

            }
        }
    }

};




/*
class Zurka{
private:
    string povod;
    vector<Osoba*> osobe;
public:
    Zurka(string povod){
        this->povod=povod;

    }
    void ispisi(){
        cout<<povod<<endl;
    }
    void dodaj(Osoba* o){
        osobe.push_back(o);

    }
    void ispisiOsobe(){
        cout<<"Povod ove zurke je: "<<povod<<endl;
        cout<<"Osobe koje prisustvuju zurci su: "<<endl;

        for (auto it=osobe.begin(); it<osobe.end(); it++){
            (*it)->predstaviSe();

        }
    }
    int kolikoJeOsoba(){return osobe.size();}

    int kolikoJeRadnika(){
        int broj=0;
        for (auto it=osobe.begin(); it<osobe.end(); it++){
            if ((*it)->identifikacija()==2)
                broj++;
        }
        return broj;

    }
    bool izbaci(const Osoba& o){
        for (auto it=osobe.begin(); it<osobe.end(); it++){
            if (o.getIme()==(*it)->getIme() && o.getPrezime()==(*it)->getPrezime()){
                osobe.erase(it);
                return true;
            }

        }
        return false;

    }

};*/

#endif // TROFEJ_HPP_INCLUDED
