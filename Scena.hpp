#ifndef SCENA_HPP_INCLUDED
#define SCENA_HPP_INCLUDED

class Scena
{
private:
    int p,j;
    int sc[20][20];
public:
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
