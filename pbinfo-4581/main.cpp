#include <fstream>
using namespace std;
ifstream fin("kpower.in");
ofstream fout("kpower.out");
int cer,k,n,i,lc,lmax;
unsigned long long x,mx,sc,smax;
bool kpower(unsigned long long x)
{
    if(x==0) return 0;
    if(x==1) return 1;
    while(x%k==0)
        x=x/k;
    if(x==1) return 1;
    else return 0;
}
int main()
{
    fin>>cer;
    fin>>k>>n;
    ///cerinta 1
    if(cer==1)
    {
        for(i=1; i<=n; i++)
        {
            fin>>x;
            if (kpower(x))
                if(x>mx) mx=x;
        }
        fout<<mx<<'\n';
    }
    ///cerinta 2
    if(cer==2)
    {
        for(i=1; i<=n; i++)
        {
            fin>>x;
            if (kpower(x))
                lc++;
            else
            {
                if(lc>lmax)lmax=lc;
                lc=0;
            }
        }
        if(lc>lmax)lmax=lc;
        fout<<lmax<<'\n';
    }
    ///cerinta 3
    if(cer==3)
    {
        for(i=1; i<=n; i++)
        {
            fin>>x;
            if (kpower(x))
            {
                lc++;
                sc+=x;
            }
            else
            {
                if(lc>lmax || lc==lmax && sc>smax)
                {
                    lmax=lc;
                    smax=sc;
                }
                lc=0;
                sc=0;
            }
        }
        if(lc>lmax || lc==lmax && sc>smax)
        {
            lmax=lc;
            smax=sc;
        }
        fout<<smax<<'\n';
    }
    return 0;
}