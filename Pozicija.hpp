#ifndef POZICIJA_HPP_INCLUDED
#define POZICIJA_HPP_INCLUDED

using namespace std;

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

    void Setx(int xx)
    {
        x=xx;
    }
    void Sety(int yy)
    {
        y=yy;
    }

    int Getx()
    {
        return x;
    }
    int Gety()
    {
        return y;
    }

    void Setp(int nx,int ny)
    {
        x+=nx;
        y+=ny;
    }
    friend ostream& operator<<(ostream& izlaz, const Pozicija& p);

    void Yup()
    {
       if(y<20){y+=1;}

    }

    void Ydown()
    {
       if(y>0){y-=1;}
    }

    void Xright()
    {
       if(x<20){x+=1;}
    }

    void Xleft()
    {
       if(x>0){x-=1;}
    }

};

#endif // POZICIJA_HPP_INCLUDED
