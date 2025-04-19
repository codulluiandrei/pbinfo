#include <iostream>
#include <fstream>
using namespace std;
 ifstream f("fermier.in");
 ofstream g("fermier.out");
long long maxx, sens[102],st[102],dr[102],n, d[102], p[102];
void deplasari_st_dr(int i)
{ int j;
    if (i==1)
     {st[i]=d[0];
     dr[i]=0;
      for (j=n;j>=1;j--)
         dr[i]+= d[j];
     }
     else
      if (i==n)
      {
          dr[i]=d[n];
          st[i]=d[0];
          for(j=1;j<=n-1;j++)
           st[i]+=d[j];
      }
      else
      {
          st[i]=st[i-1]+d[i-1];
          dr[i]=dr[i-1]-d[i-1];
      }
 if (st[i]<dr[i])
    sens[i]=1;
    else
    sens[i]=-1;
}
int km()
{ long long nr,nr1,rest;
  int i,j,depoz;
 nr=0;
 depoz=0;
 i=1;
 rest=maxx;
 while (i<=n)
 {
     if (depoz==0)
     { rest=maxx;
       if (p[i]!=0)
       if (sens[i]==1)
        {
            nr1=p[i]/maxx;
            nr+=nr1*2*st[i];
            rest=maxx*nr1;
            if (p[i]%maxx!=0)
             {
                 nr+=st[i]; depoz=1;rest+=maxx;}
                 if (rest<p[i])
                 {
                     rest=0;
                     p[i]-=rest;
                 }
                 else
                 {
                      rest=rest-p[i];
                      p[i]=0;
                 }
         }
        else
        {
            nr1=p[i]/maxx;
            nr+=nr1*2*dr[i];
            rest=maxx*nr1;
            if (p[i]%maxx!=0)
             {
                 nr+=dr[i]; depoz=1; rest+=maxx;
              }
            if (rest<=p[i])
                 {
                    p[i]-=rest;
                    rest=0;
                 }
                 else
                 {
                      rest=rest-p[i];
                      p[i]=0;
                 }
            }
        else i++;
     }
       else
         if (rest==0 || i==n)
          //ma intorc in depozit
           if (sens[i]==1)
           {
               nr+=st[i];
            depoz=0;
            if (p[i]==0)   i++;
           }
           else
           {
            nr+=dr[i];
            depoz=0;
            if (p[i]==0) i++;
           }
           else
           {
               //merg la urmatorul
               if (d[i]<st[i]+dr[i+1])
                   nr+=d[i];
                   else
                   nr+=st[i]+dr[i+1];
                   if (rest<p[i+1])
                      {
                          p[i+1]-=rest;
                          rest=0;
                          depoz=1;
                      }
                      else
                      {
                          rest-=p[i+1];
                           p[i+1]=0;
                      }
             i++;
           }
     }
    return nr;
}
int main()
{ int i;
    f>>n>>maxx;
    for(i=0;i<=n;i++)
        f>>d[i];
    for(i=1;i<=n;i++)
     f>>p[i];
    for (i=1;i<=n;i++)
     deplasari_st_dr(i);
    g<<km();
    return 0;
}