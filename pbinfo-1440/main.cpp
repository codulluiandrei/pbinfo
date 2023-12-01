#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    ifstream f("nr.in");
    ofstream g("nr.out");
    long x,z,p=1,y;
    int n,k,c,i,j;
    f>>k>>n>>x;

// cerinta a)

    z=(long)pow(2,k-1);
    g<<z<<endl;

    //cerinta b)

    z=0;
    i=1;
    do
    {
        c=n%2;
        if(c!=0)z=z+i*p;
        p=p*10;
        i++;
        n=n/2;
    }
    while (n>0);
    g<<z<<endl;

    //cerinta c

    z=1;
    for(j=2; (j<=511) && (z<x); j++)
    {
        n=j;
        p=1;
        y=z;
        z=0;
        i=1;
        do
        {
            c=n%2;
            if(c!=0)z=z+i*p;
            p=p*10;
            i++;
            n=n/2;
        }
        while (n>0);
    }
    if((z==x)||(j==512)) g<<z;
    else g<<y;
    g<<endl;
    return 0;
}


