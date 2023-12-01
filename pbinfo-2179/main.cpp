//prof.Carmen Minca  - 100p
#include <bits/stdc++.h>
using namespace std;
int main()
{ int n, v[3505], p[3505];
  long d,e;
  int i, max=0,x,a,b,c,j;
  ifstream f("max3.in");
  ofstream g("max3.out");
  f>>n;
  for(i=1;i<=n;i++)
  { f>>x; v[i]=x;
    if(x<10) p[i]=10;
      else if(x<100)
	    { a=x/10; b=x%10; p[i]=100;
	      if (a<b)v[i]=b*10+a;
	    }
	    else
	    { a=x/100; x=x%100; b=x/10; c=x%10;p[i]=1000;
	      if(a<b) { x=a; a=b; b=x;}
	      if(a<c) { x=a; a=c; c=x;}
	      if(b<c) { x=b; b=c; c=x;}
	      v[i]=100*a+10*b+c;
	    }
    if(max<v[i])max=v[i];
    }
    g<<max<<endl;
    for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++)
    { d=v[i];d=d*p[j]+v[j];
      e=v[j]; e=e*p[i]+v[i];
      if (d<e)
	 {x=v[i]; v[i]=v[j]; v[j]=x;
	  x=p[i]; p[i]=p[j]; p[j]=x;}
    }
    for(i=1;i<=n;i++) g<<v[i];
    
    g.close();
}
