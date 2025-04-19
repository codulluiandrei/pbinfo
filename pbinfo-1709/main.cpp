#include <fstream>
using namespace std;
ifstream f("asort.in");
ofstream g("asort.out");
long long n,r,t; int k;
int numar_poz(int k)///determin numarul situat pe pozitia k in sirul "asortat"
{
    long long nrc;
    if(r==0)return k;
    if(r%2!=0)
       if(k%2!=0) nrc=(r+k)%n;
       else nrc=(n+k-r)%n;
    else
       if(k%2==0) nrc=(r+k)%n;
       else nrc=(n+k-r)%n;
   if(nrc==0)nrc=n;
   return nrc;
}
int main()
{
    int p;
    f>>p>>n>>r>>k>>t;
    r=r%n;
    if(p==1)
        g<<numar_poz(k)<<'\n';
    else
    {
        int pozt;///pozitia numarului T in sirul "asortat"
        int pred,succ, poz_pred, poz_succ;
        if(t%2==0) pozt=(n+t-r)%n;
          else pozt=(t+r)%n;
        if(pozt==0)pozt=n;
        if(pozt==1) { poz_pred=n; poz_succ=2; }
          else
          if(pozt==n){ poz_pred=n-1; poz_succ=1; }
           else { poz_pred=pozt-1; poz_succ=pozt+1; }
        pred=numar_poz(poz_pred);
        succ=numar_poz(poz_succ);
        g<<pred<<" "<<succ<<'\n';
    }
    return 0;
}