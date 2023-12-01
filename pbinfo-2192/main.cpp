#include <fstream>

using namespace std;

ifstream f("talent.in");

ofstream g("talent.out");

long x,vip,p,c[10],n,maxd,d;

int pali(long x)
{
    int i,k=0,nen=0;
    d=0;
    for(i=0; i<=9; i++) c[i]=0;
    while(x) c[x%10]++,nen+=(x%10!=0),x=x/10;
    for(i=0; i<=9; i++)
    {
        k+=(c[i]%2!=0);
        d+=(c[i]!=0);
    }
    if(nen==1 && c[0]!=0) return 0;
    return (k<2);
}
int main()
{
    f>>n;
    while(n--)
    {
        f>>x;
        if(pali(x))
        {
            p++;
            if(!vip || maxd<d || maxd==d && x<vip)vip=x,maxd=d;
        }
    }
    g<<p<<' '<<vip<<'\n';

    f.close();
    g.close();
    return 0;
}
