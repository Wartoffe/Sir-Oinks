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
        int hs=hs1;
        int time=time1;
        int levelnum=levelnum1;
        string ime=ime1;
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
