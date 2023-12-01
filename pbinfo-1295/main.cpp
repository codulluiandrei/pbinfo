#include <fstream>
using namespace std;
int j,n,p,y,v,nrp,li,lf,nr,m,num;
int nrprim(int t)
{
    long long i,x;
    bool prim;
    x=t;
    while(true)
    {
        prim=true;
        for(i=2;i*i<=x;i++)
           if(x%i==0){prim=false;break;}

    if(prim) break;
        x++;
    }

    return x;
}
int main()
{
   ifstream f("cifpagini.in");
   ofstream g("cifpagini.out");
   f>>n>>p>>v;
   y=p;
    for(j=1;j<=n;j++)
       {
          nrp=nrp+y;
          y=nrprim(y+1);
       }

    if(v==1) g<<nrp;
    else if(v==2)
    {
              lf=9;
              li=1;
              nr=1;
              while(true)
               {
                   if(nrp>=lf) m=m+lf*nr;
                   else if(nrp<lf) {m=m+nr*(nrp-li+1);break;}
                   lf=lf*10;
                   li=li*10;
                   nr++;
               }
        g<<m;
    }
    return 0;
}