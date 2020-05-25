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
                {
                    int nesto= p1.Getpare();
                    cout<<"imate:"<<nesto<<endl;;
                    cout<<"Unesite broj iteme koji zelite da kupiti(kolicina)"<<endl;
                    int br;
                    cin>>br;
                    p1.Kupovanje(br,nesto);
                    Izvestaj<<"Korisnik je pristupio Radnji i pokusao da kupi br itema iz radnje"<<endl;;

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


/*
    while(opstop!=0)
    {

        cout<<"pomeri te se koristeci w,a,s,d"<<endl;
        char pokret;
        cin>>pokret;



        if(pokret=='w')
        {
            Sir.Wmove();
        }
        if(pokret=='a')
        {
            Sir.Amove();
        }
        if(pokret=='s')
        {
            Sir.Smove();
        }
        if(pokret=='d')
        {
            Sir.Dmove();
        }
        if((Sir.Getx()==s1.Getp())&&(Sir.Gety()==s1.Getj()))
        {
            cout<<"pobedili ste nivo Yay"<<endl;
            opstop=0;
        }
    }
*/




    /*Pozicija p1(5,7);
    Dijalog d1("Dijalog.txt",0);
    Izazov c1(0,1000,"Wartoffe",4,0,0,0,6,8);
    Korisnik user1(200,27,1,"Wartoffe");
    Level lvl1(1,7,8,0,0,1,0,8,9,20,"Grass",30,0,0,0,19,13,0);
    Prodavac prodava1("Dijalog.txt",0,200,20,20,0);
    Sir_Oinks sir(2,1,0,0,0,0,20);
    Scena s1(10,8);
    Trofej trofi1("Yay",100,1,8,7);
    Aht trofi2("Nay",200,1,9,1);
    Aht trofi3("Meh",180,1,6,4);
    /*Turf t("Thiccice",4,1,1,0,7,16);
    cout<<t;*/
    //citajTxt("Korisnik.txt");
   /* cout<<user1;
    cout<<trofi1;
    cout<<user1.getNumofusers();
    Achivements a;
    a.dodaj(&trofi1);
    a.dodaj(&trofi2);
    a.dodaj(&trofi3);
    //a.ispisiArhive();-ispis
    a.Searchfor();//ovo je otprilike search/filter(radi)

    a.Kill(trofi2);//-brisanje
    //a.ispisiArhive();*/

}
