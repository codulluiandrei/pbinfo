#include <bits/stdc++.h>
using namespace std;

long long a,b,w,ok,d,dif,p,k,z;
long long cmmdc(long long a,long long b)
{
   while(b)
   {
       long long r=a%b;a=b;b=r;
   }
   return a;
}
long long cmmmc(long long a,long long b)
{   long long c=cmmdc(a,b);
    return (a/c)*b;
}

int main()
{
   cin>>a>>b;
   if(a>b) swap(a,b);
   z=(1ll<<62);
   ok=0;
   dif=b-a;
   for(d=1;d*d<=dif;++d)
   {
      k=d;
      p=(k-a); while(p<0) p+=k;
      w=cmmmc(a+p,b+p);
      if(w<z){ok=p;z=w;}
     //---------------------
      k=dif/d;
      p=(k-a); while(p<0) p+=k;
      w=cmmmc(a+p,b+p);
      if(w<z){ok=p;z=w;}
   }

   cout<<ok<<'\n';
   return 0;
} 