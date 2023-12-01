#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in("roboti2.in");
    ofstream out("roboti2.out");
    long p[100000],a[100000],v,x,ok;
    long n,i,max=1,s,d,ls=1,ns,nd;
    int serie,cs,antdr;
    in>>v>>n;
    for(i=0;i<n;i++)
      in>>p[i];
    if(v==1) //cerinta 1
     {
      i=1; x=p[0]; ok=0;
      while(i<n && ok<2)
       {
         if(p[i]>p[i-1])
           ls++;
         else
          {
            if(ls>max)
              max=ls;
            ls=1;
          }
         i++;
         //ciclarea cautarii
         if(i==n)
           {
             if(x>p[i-1])
               { ls++; i=1; }
             ok++; //numai inca o ciclare
           }
       }
       out<<max;
     }
    else  //cerinta 2
     {
       sort(p, p+n);
       //aranjare
       a[0]=p[0];
       s=0; d=n;
       serie=0;
       ns=0;nd=0;
       antdr=0;
       for(i=1;i<=n-1;i++)
        {
          //daca este cap de serie, adica primuldintr-o serie de nr. care se repeta
          if(i<n-1 && p[i]==p[i+1] && p[i-1]!=p[i])
            cs=1;
          else
            cs=0;
          //daca am pus mai putini sau egal in st si dr sau
          // este intr-o serie de egale sau
          // cel dinaintealui l-am pus in dreapta dar nu a fost cap de serie
          if(ns<=nd || serie || (antdr && !cs) )//merge stanga
            {
              s++;
              a[s]=p[i];
              ns++;
              antdr=0;
            }
          else //merge dreapta
            {
              d--;
              a[d]=p[i];
              nd++;
              antdr=1;
            }
          if(p[i]==p[i-1])
            serie++;
          else
            serie=0;
         }
       for(i=0;i<n;i++)
         out<<a[i]<<' ';
     }
    in.close();
    out.close();
    return 0;
}
