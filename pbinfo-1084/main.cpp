# include <fstream>
using namespace std;
ifstream f("tren.in");
ofstream g("tren.out");
int x=1,t,y,z,t1,l,h,m,sta,s,p,am2,i,p1,p2,u;
int main()
{ f>>t;
  f>>l>>h>>m>>sta;
  u=h*60+m+sta;
  if(l==1) t1++,p1=u;
      else p2=u;
  for(i=2;i<=t;i++)
  {f>>l>>h>>m>>sta;
   s=h*60+m; p=s+sta;
   if(s-u>y) y=s-u;
   if(s>p1+1 && am2==1 && p2>p1) x++,am2=0;
   if(l==1) x++,t1++,p1=p;
     else if (s>p1) x++,am2=0,p2=p;
	     else if (p>p1) p2=p,am2=1;
   u=(p1>p2)?p1:p2;
  }
  if(am2)x++;
  z=(t1>t-t1)?t1:t-t1;
  if(y)y--;
  g<<z<< " " <<x<< " " <<y;
  f.close();g.close();
}