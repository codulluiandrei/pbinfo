#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("wind.in");
ofstream g("wind.out");
long long d,smin,smax,divx,poz,pozmax,minimm=99999999,C,n,i,k,s[200001],v[10001],x,j,dif,minim=99999999,numar,gasit;
int main()
{
    f>>C;
    if(C==1)
    {
        f>>n;
        for(i=1; i*i<=n; i++)
            if(n%i==0)
            {
                k++;
                if(i!=n/i)
                    k++;
            }
        g<<k-1;
    }
    else
    {
        f>>n;
        for(i=1; i<=n; i++)
        {
            f>>x;
            s[i]=s[i-1]+x;
        }
        for(i=1; i*i<=n; i++)
            if(n%i==0)
            {
                k++;
                v[k]=i;
                if(i!=n/i and n/i!=n)
                {
                    k++;
                    v[k]=n/i;
                }
            }
        for(i=1; i<=k; i++)
        {
            x=v[i];
            smin=99999999999;
            smax=-99999999999;
            for(j=x; j<=n; j=j+x)
            {
                if ( s[j]-s[j-x]< smin)
                    smin=s[j]-s[j-x];
                if (s[j]-s[j-x] >= smax)
                {
                    smax=s[j]-s[j-x];
                    poz=j-x+1;
                }
            }
            dif=smax-smin;
            if(dif<minimm)
            {
                minimm=dif;
                divx=x;
                pozmax=poz;
            }
            else if(dif==minimm && x<divx)
            {
                divx=x;
                pozmax=poz;
            }
        }
        g<<n/divx<<" "<<pozmax;
    }
    return 0;
}