#include <fstream>
using namespace std;
ifstream f("forus.in");
ofstream g("forus.out");
int nrdiv(int N)
{
    int d,nrd=1;
    for(d=1;d*d<N;d++)
        if(N%d==0)nrd+=2;
    if(d*d==N) ++nrd;
       return nrd;
}
int main()
{
    int C,N,nr;
    f>>C>>N;
    if(C==1)
    {
        int r=0,ok;
        for(int i=1; i<=N; i++)
        {
            f>>nr;
            //cout<<nr<<" ";
            ok=1;
            while(nr && ok)
            {
                if (nr%10==0)ok=0;
                nr=nr/10;
            }
            r=r+ok;
        }
        g<<r<<endl;
    }
    else
    {   int y,p,nrc,x,pr,ult,pu,xmin,nrdm,nrd,z;
        for(int i=1; i<=N; i++)
        {
            f>>nr;
            p=1;nrc=1;pu=10;
            xmin=nr; nrdm=nrdiv(nr);
            x=nr;
            while(x>0)
            {
                x=x/10;
                p=p*10;
                nrc++;
            }
            p=p/10;z=p;
            for(int i=1; i<nrc; i++)
            {
                pr=nr/p;
                ult=nr%p;
                x=ult*pu+pr;
                if(x/z>0)
                {
                    nrd=nrdiv(x);
                    if(nrd<nrdm)
                    {
                        xmin=x;
                        nrdm=nrd;
                    }
                    else
                        if(nrd==nrdm) xmin=min(xmin,x);
                }
                pu=pu*10;
                p=p/10;
            }
            g<<xmin<<" ";
        }
g<<endl;}
return 0;
}