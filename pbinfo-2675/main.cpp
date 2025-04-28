#include <bits/stdc++.h>
using namespace std;
int c[1300],apa[1300],suc[1300],n,suma[1300];
void Citire()
{
    int k,i,x,y;
    ifstream f("scara.in");
    f >> n >> k;
    for(i = 1; i <= k; i++)
    {
      f >> x >> y;
      apa[x] = y;
    }
    f >> k;
    for(i = 1; i <= k; i++)
    {
      f >> x >> y;
      suc[x] = y;
    }
    f.close();
}
void Calcul()
{
     int i,j;
     c[1]=1;suma[1]=0;
     for(i=2;i<=n;i++) {c[i]=30000;suma[i]=30000;}
     for(i=1;i<n;i++)
     {
         if((c[i+1]>c[i]+1)||((c[i+1]==c[i]+1)&&(suma[i+1]>suma[i])))
         {c[i+1]=c[i]+1;suma[i+1]=suma[i];}
         if(apa[i])
             for(j=1;(j<=apa[i])&&(i+j<=n);j++)
                 if((c[i+j]>c[i]+1)||((c[i+j]==c[i]+1)&&(suma[i+j]>suma[i])))
                 {c[i+j]=c[i]+1;suma[i+j]=suma[i];}
        if(suc[i])
             for(j=1;(j<=2*suc[i])&&(i+j<=n);j++)
                 if((c[i+j]>c[i]+1)||((c[i+j]==c[i]+1)&&(suma[i+j]>suma[i]+(j+1)/2)))
                 {c[i+j]=c[i]+1;suma[i+j]=suma[i]+(j+1)/2;}
     }
}
void Afisare()
{
    ofstream g("scara.out");
    g << c[n] << " " << suma[n] << "\n";
    g.close();
}
int main()
{
    Citire();
    Calcul();
    Afisare();
    return 0;
}