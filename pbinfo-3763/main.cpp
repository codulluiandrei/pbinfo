#include <fstream>
#include <cmath>
#define Nmax 4000
using namespace std;

long long  v[100001];
int  prim[600], np;
bool x[Nmax];
ifstream f("puternic.in");
ofstream g("puternic.out");

void Ciur()
{
    int j, i;
    prim[1] = 2;         // in vectorul prim retinem numerele prime < Nmax
    np = 1;                      //numarul numerelor prime < Nmax
    for(i = 3; i*i<=Nmax; i+=2)
        if (x[i]==0)
        {
            for (j=i*i; j<=Nmax; j=j+2*i) x[j]=1;
            prim[++np]=i;
        }
    while (i<=Nmax)
    {
       if (x[i]==0) prim[++np]=i;
       i+=2;
    }
  }


int puternic (long long x)
{
    if (x==1) return 0;
    for (int i=1; i<=np&& x!=1; i++)
    {
        int e=0;
        while (x%prim[i]==0)
        {
            x=x/prim[i];
            e++;
        }
        if (e==1) return 0;
    }
    if (x==1) return 1;
    long long r2=sqrt(x);                     // radacina patrata a lui x
    if (r2*r2==x ||(r2+1)*(r2+1)==x) return 1;  
                   // am evitat eventualele erori de precizie
    long long r3=cbrt(x);                    //radical de ordin 3 din x
    if (r3*r3*r3==x ||(r3+1)*(r3+1)*(r3+1)==x) return 1; 
                   // am evitat eventualele erori de precizie
    return 0;
}
long long  concatenare (long long   x, long long  y)      
                // concatenarea a doua numere
{
    long long p=1,yy=y;
    while (yy!=0)
    {
        yy=yy/10;
        p=p*10;
    }
    return x*p+y;
}
int main()
{
    int n,p,i,k=0,gasit;
    long long nr,x;
    Ciur();
    f>>p>>n;
    for (i=1; i<=n; i++)
    {
        f>>x;
        if (puternic(x)==0)
        {
            k++; //  numarul valorilor din sir care nu sunt puternice
            v[k]=x;
        }
    }
    if (p==1)
    {
        g<<n-k;
    }
    else
    {
        gasit=0;
        for (i=1; i<=k/2; i++)
        {
            nr=concatenare(v[i],v[k+1-i]);
            if (puternic(nr))
            {
                gasit=1;
                g<<v[i]<<' '<<v[k+1-i]<<'\n';
            }
        }
        if (gasit==0)
            g<<-1;
    }
}
