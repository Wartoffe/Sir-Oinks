#ifndef DIJALOG_HPP_INCLUDED
#define DIJALOG_HPP_INCLUDED

using namespace std;

class Dijalog
{
private:

    string dijalog;
    int karma;

public:

    Dijalog(string di,int k)
    {
        dijalog=di;
        karma=k;
    }

    void Saysomethingiamgivinguponyou()
    {
        cout<<dijalog<<endl;


    }

};

#endif // DIJALOG_HPP_INCLUDED
