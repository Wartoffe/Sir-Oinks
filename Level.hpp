#ifndef LEVEL_HPP_INCLUDED
#define LEVEL_HPP_INCLUDED

#include "Scena.hpp"
#include "Sir_Oinks.hpp"
#include "Turf.hpp"
using namespace std;

class Level
{
private:

    int id;
    Scena slvl1;
    Sir_Oinks player1;
    Turf lvl1;
    bool izazov;


public:

   Level(int id1,int pp,int jj,double v1,bool gr1,bool hat1,bool clinging1,int xx,int yy,double vMax1,string ime1,double maxv1,bool bouncy1,bool slip1,bool sharp1,int xx1,int yy1,bool izazov1):slvl1(pp,jj),player1(v1,gr1,hat1,clinging1,xx,yy,vMax1),lvl1(ime1,maxv1,bouncy1,slip1,sharp1,xx1,yy1)
   {
       id=id1;
       izazov=izazov1;
   }
    //ovde se pusti himna Srbije kolko je ovo dugacko
};

#endif // LEVEL_HPP_INCLUDED
