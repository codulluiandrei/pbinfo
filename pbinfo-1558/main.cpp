//#include <iostream>
#include <fstream>
using namespace std;

ifstream f("npe.in");
ofstream g("npe.out");

int n,p,l,c;
int main()
{
    int k,nr1,nr;
    f>>n;
    if(n==1)
    {
        g<<"1 1 1"<<endl;
        return 0;
    }
    p=1;
    nr=0;
    while(n>nr+p*p)
    {
        nr=nr+p*p;
        p++;
    }

    n=n-nr;
    if(n==1)
    {
        g<<p<<" 1 1"<<endl;
        return 0;
    }

    k=p;
    int r=1;
    while(n>4*k-4 && k>0)
    {
        n=n-4*k+4;
        k=k-2;
        r++;
    }

    if(n==1)l=c=r;
    else
    {
        k=p-2*(r-1);
        if(n<=k)
        {
            l=r;
            c=r-1+n;
        }
        else
        {
            n=n-k;
            if(n<=k-1)
            {
                l=r+n;
                c=p+1-r;

            }
            else
            {
                n=n-k+1;
                if(n<=k-1)
                {
                    l=p+1-r;
                    c=p-r+1-n;

                }
                else
                {
                    n=n-k+1;
                    l=p+1-r-n;
                    c=r;

                }
            }
        }
    }
    g<<p<<" "<<l<<" "<<c<<endl;
    return 0;
}


