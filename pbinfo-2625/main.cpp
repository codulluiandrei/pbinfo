//100p
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("viitor.in");
ofstream g("viitor.out");
int n,m,k,x,y,u,i,nr,px,py,s,a,b;
struct zi{ int st,dr,sum;} Z[100001];
struct interval{int st,dr;
                friend bool operator < (interval I1, interval I2)
                    {return (I1.st <I2.st || I1.st==I2.st && I1.dr<I2.dr); };
                } Interval[100005];
int cb(int a, int st, int dr)
{ int m;
  while(st<=dr) {m=(st+dr)/2;
                 if(a>=Z[m].st && a<=Z[m].dr) return m;
                   else if(a<Z[m].st) dr=m-1;
                        else st=m+1;
                 }
  return st;
}
int main()
{ f>>n>>m>>k;
  for(i=1;i<=m;++i) f>>Interval[i].st>>Interval[i].dr;
  sort(Interval+1, Interval+m+1);
  u=0;
  for(i=1;i<=m;++i) {x=Interval[i].st; y=Interval[i].dr;
                     if(x>u+1) {nr++;Z[nr].st=u+1; Z[nr].dr=x-1;Z[nr].sum=Z[nr-1].sum+(x-u-1);}
                     u=max(u,y);}
  if(u<n){nr++;Z[nr].st=u+1; Z[nr].dr=n;}
  for(i=1;i<=k;i++)
  { f>>x>>y;
    s=0;
    px=cb(x,1,nr);
    py=cb(y,1,nr);
    a=max(Z[px].st,x);
    b=min(Z[px].dr,y);
    if(a<=b) s=b-a+1;
    if(px!=py)
    {px++;
     a=max(Z[py].st,x);
     b=min(Z[py].dr,y);
     if(a<=b) s+=b-a+1;
     py--;
     s+=(Z[py].sum-Z[px-1].sum);
    }
    g<<s<<'\n';
    }
  f.close(); g.close();
    return 0;
}