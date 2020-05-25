#ifndef SCENA_HPP_INCLUDED
#define SCENA_HPP_INCLUDED
#include <fstream>
#include <vector>
#include "Sir_Oinks.hpp"
class Scena
{
private:
    int p,j;
    int sc[20][20];
    vector <Turf*> ob;

public:




    void dodaj(Turf* t){
        ob.push_back(t);
    }

    void Ispisscene(Sir_Oinks* s){

    for(int i=0;i<20;i++)
    {
        for(int p=0;p<20;p++)
        {
            if(i==0 && p==19)
            {
                cout<<" X";
            }

            else if(s->TellifOinks(p,i))
            {
                cout<<"  O ";
            }
            else if(Searchfor(i,p))
            {
                cout<<" R  ";
            }
            else
                cout<<"  | ";
        }
        cout<<endl;
    }
                    }


    int Searchfor(int i,int p){


                for (auto it=ob.begin(); it<ob.end(); it++){
                        if ((*it)->Geti()==i && (*it)->Getp()==p){return 1;}
                        }
                        return 0;
    }


    int Impass(int p,int i)
    {
        for (auto it=ob.begin(); it<ob.end(); it++){
                        if ((*it)->Geti()==i && (*it)->Getp()==p){return 0;}
                        }
                        return 1;
    }


    Scena(int pp,int jj)
    {
        p=pp;
        j=jj;
    }

    int Getp()
    {
        return p;
    }

    int Getj()
    {
        return j;
    }


};

#endif // SCENA_HPP_INCLUDED
