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

    void Setp(int nx,int ny)
    {
        x+=nx;
        y+=ny;
    }
};

#endif // POZICIJA_HPP_INCLUDED
