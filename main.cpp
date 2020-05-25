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

ofstream Izvestaj ("Izvestaj.txt");

int x;

int Korisnik::usersnum=0;

int pom=0;

vector <Korisnik*> kori;

void dodaj(Korisnik* k){
        kori.push_back(k);
    }

void Unesiuvektor(string line)
    {
        string i;
        ifstream fajl(line);

        if (fajl.is_open())
        {
            while(getline(fajl,i))
            {
                Korisnik* ime=new Korisnik(i,pom++);
                dodaj(ime);

            }
            fajl.close();
        }

        else
            cout <<"Failovano";
    }



void Listak(){
        cout<<"Lista : "<<endl;

        for (auto it=kori.begin(); it<kori.end(); it++){
            (*it)->about();

        }
    }


void Searchfor(){

                cin>>x;

                for (auto it=kori.begin(); it<kori.end(); it++){
                        if ((*it)->getid()==x){
                            (*it)->about();
                            cout<<"Acc je uspesno pristupljen"<<endl;
                            Izvestaj<<"Korisnik je odlucio da izabere akaun pod id"<<x<<endl;
                            return;
                        }
        }
        cout<<"Acc nije uspesno pristupljen >:( molivas unesite pravi acc ili napravite novi";
                    exit(1);
    }


void Givepoints(){

            int score;
                for (auto it=kori.begin(); it<kori.end(); it++){
                        if ((*it)->getid()==x){
                            (*it)->Winpoints();
                            (*it)->Scoreispis();
                            score=(*it)->Scoreget();
                        }


        }
                        Izvestaj<<"Korisnik pobedjuje igricu i ima :"<<score<<" pojena"<<endl;


    }


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


void citajTxt(string line)
{
    string linija;
    ifstream fajl (line);
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


    if(Izvestaj.is_open())
    {
        Izvestaj<<"Pocetak izvestaja"<<endl;
    }



    Unesiuvektor("Korisnik.txt");

    int opstop=1;
    Scena s1(19,0);
    Turf t("Rock",1,1,1,1,5,7);
    s1.dodaj(&t);

    Sir_Oinks Sir(1,1,0,0,0,19,2);
    Prodavac p1("Prijatan vam dan",2,30,20,20);
    while(opstop!=0)
    {
        cout<<"1.Napravite novi akaunt"<<endl<<"2.Izaberite akaunt"<<endl<<"0.Da izadjete"<<endl;
        cin>>opstop;

        if(opstop==0)
            {
                exit(2);
            }

        if(opstop==1)
        {
            cout<<"Unesite vase korisnicko ime"<<endl;
            string imek;
            cin>>imek;
            Korisnik* ime=new Korisnik(imek,pom++);
            dodaj(ime);
            ofstream File ("Korisnik.txt" , ios::app);
            if(File.is_open())
            {
                File<<imek<<endl;
            }
            File.close();

            Izvestaj<<"Korisnik je napravio novi akaunt "<<imek<<endl;


        }

        else
        {
            cout<<"Unesite redni broj akaunta da bi ga izabrali"<<endl;
            Listak();

            Searchfor();


        }


        while(opstop!=0)
        {

            cout<<"1.Za prodavnicu"<<endl<<"2.Za igricu"<<endl<<"0.za izlaz";

            cin>>opstop;



            if(opstop==1)
            {
                cout<<"Dobrodosli u prodavnicu"<<endl;




                Izvestaj<<"Korisnik je odlucio da udje u prodavnicu"<<endl;
                cout<<"1.da kupite,0.da izadjete iz cele aplikacije"<<endl;
                cin>>opstop;

                if(opstop==1)

                    cout<<"Unesite broj iteme koji zelite da kupiti(kolicina)"<<endl;
                    int br;

                {
                    int nesto;
                    auto it=kori.begin();
                    for (auto it=kori.begin(); it<kori.end(); it++){
                        if ((*it)->getid()==x){
                            nesto=(*it)->Givepare();
                            cout<<"imate:"<<nesto<<endl;
                            cin>>br;
                            p1.Kupovanje(br,nesto,*it);

                        }
                    }




                    Izvestaj<<"Korisnik je pristupio Radnji i pokusao da kupi " <<br<<" itema iz radnje"<<endl;;

                }

            }
            if(opstop==2)
            {
                Izvestaj<<"Korisnik pristupa igrici"<<endl;
                Sir.Gamestart(0,19);
    while(opstop!=4)
    {

        cout<<"pomeri te se koristeci w,a,s,d"<<endl<<"cilj je dovesti Sir Oinksa(O)do kraja(X)"<<endl;

        s1.Ispisscene(&Sir);
        char pokret;
        cin>>pokret;



        if(pokret=='w')
        {
            if(s1.Impass(Sir.Getx(),Sir.Gety()-1)){Sir.Smove();}

        }
        if(pokret=='a')
        {
            if(s1.Impass(Sir.Getx()-1,Sir.Gety())){Sir.Amove();}
        }
        if(pokret=='s')
        {
            if(s1.Impass(Sir.Getx(),Sir.Gety()+1)){Sir.Wmove();}
        }
        if(pokret=='d')
        {
            if(s1.Impass(Sir.Getx()+1,Sir.Gety())){Sir.Dmove();}
        }
        if((Sir.Getx()==s1.Getp())&&(Sir.Gety()==s1.Getj()))
        {
            cout<<"pobedili ste nivo Yay"<<endl;
            opstop=4;
            Givepoints();

        }
    }
            }
        }
    }
    Izvestaj.close();


}
