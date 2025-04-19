#include <fstream>
using namespace std;
ifstream fin("cifmaxmin.in");
ofstream fout("cifmaxmin.out");
int n,x,cmin,cmax,nmin,nmax,catepare,cateimpare;
int main()
{
    int i,uc,nr,cx;
    nmin=100;
    nmax=9;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x;
        cx=x;
        cmin=9;
        cmax=0;
        while(cx!=0)
        {
            uc=cx%10;
            if(uc<cmin)
                cmin=uc;
            if(uc>cmax)
                cmax=uc;
            cx=cx/10;
        }
        if(x%2==0)
        {
            nr=cmax*10+cmin;
            catepare++;
            if(nr>nmax)
                nmax=nr;
        }
        else
        {
            nr=cmin*10+cmax;
            cateimpare++;
            if(nr<nmin)
                nmin=nr;
        }
    }
    fout<<nmax<<" "<<catepare<<" "<<nmin<<" "<<cateimpare;
    return 0;
}