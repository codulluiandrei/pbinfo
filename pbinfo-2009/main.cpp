#include <fstream>
#include <iostream>
using namespace std;
ifstream f ("accesibil.in");
ofstream g ("accesibil.out");
int accesibil (int n)// verific daca n este accesibil
{
    int u,c;
    if (n<10) return 0;
    u=n%10;
    n=n/10;
    while (n!=0)
    {
        c=n%10;
        if (c+1!=u) return 0;
        u=c;
        n=n/10;
    }
    return 1;
}
int devine_accesibil(int n)
{
    if(accesibil(n)|| n<100) return 0;
    long long  p=1;
    int y;
    while (p<=n)
    {
        y=n/(p*10)*p+n%p;
        if (accesibil(y))
        {
            //cout<<y<<' ';
            return 1;}
        p=p*10;
    }
return 0;
}
int main()
{
    int p,n,k,x,nr=0,m1=0,m2=0,m3=0;
    f>>p>>k>>n;
    if (p==1)
    {
        for (int i=1;i<=n; i++)
        {
            f>>x;
            if (accesibil(x))
            {
                if (x>=m1) { m3=m2;m2=m1;m1=x;}
                else
                if (x>=m2) { m3=m2;m2=x;}
                else
                if (x>=m3) { m3=x;}
            }
        }
        if (m3==0) g<<-1<<'\n';
        else g<<m3<<' '<<m2<<' '<<m1<<'\n';
    }
    else if (p==2)
    {
        for (int i=1;i<=n; i++)
        {
            f>>x;
             // g<<'\n'<<i<<' '<<x<<' ';
            if (devine_accesibil(x))
            {
              //  g<<x;
                 nr++;
            }
        }
        g<<nr<<'\n';
    }
     else if (p==3)
     {
         for (int i=1;i<=k;i++) g<<i;
         if (k!=9)
         {
             g<<' ';
             for (int i=1;i<=k;i++) g<<9-k+i;
         }
          g<<'\n';
     }
     else
     {
         g<<(10-k)/2<<' '<<(10-k+1)/2<<'\n';
     }
    return 0;
}