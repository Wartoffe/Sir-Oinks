#ifndef KORISNIK_HPP_INCLUDED
#define KORISNIK_HPP_INCLUDED

using namespace std;

class Korisnik
{
private:

    int hs;
    int time;
    int levelnum;
    string ime;
    static int usersnum;
public:

    Korisnik(int hs1,int time1,int levelnum1,string ime1)
    {
        hs=hs1;
        time=time1;
        levelnum=levelnum1;
        ime=ime1;
        usersnum++;
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
};

#endif // KORISNIK_HPP_INCLUDED
