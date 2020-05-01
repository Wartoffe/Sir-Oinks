#ifndef POZICIJA_HPP_INCLUDED
#define POZICIJA_HPP_INCLUDED

class Pozicija
{
private:

    int x;
    int y;
public:

    Pozicija(int xx,int yy)
    {
        x=xx;
        y=yy;
    }

    /*void Setx(int xx)
    {
        x=xx;
    }*/
    void Sety(int yy)
    {
        y=yy;
    }

    /*int Getx()
    {
        return x;
    }*/
    int Gety()
    {
        return y;
    }

    /*void Setp(int nx,int ny)
    {
        x+=nx;
        y+=ny;
    }*/
};

#endif // POZICIJA_HPP_INCLUDED
