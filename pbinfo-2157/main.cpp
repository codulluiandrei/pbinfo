#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
long cmmdc(long a, long b)
{
    while(a!=b)
      if(a>b)
        a=a-b;
      else
        b=b-a;
    return a;
}
int main()
{
    ifstream in("bomboane3.in");
    ofstream out("bomboane3.out");
    int p,n,i,k=0,j,nb;
    long b[10001], c[10001], min, s, r, st, dr;
    in>>p>>n;
    // cout<<n<<endl;
      if(p==1) //cerinta 1
     {
       in>>b[1]; min=b[1];
       for(i=2;i<=n;i++)
         {
           in>>b[i];
           if(b[i]<min)
             min=b[i];
         }
       for(i=1;i<=n;i++)
         b[i]=b[i]-min;
       i=1;
       while(b[i]==0)
         i++;
       k=b[i];
       for(i=2;i<=n;i++)
         if(b[i]!=0)
           k=cmmdc(k,b[i]);
       out<<k;
     }
    else //cerinta 2
     {
        for(i=1;i<=n;i++)
          {
            in>>b[i];
            c[i]=sqrt(2*b[i]);
            if(c[i]*(c[1]+1)>2*b[i])
              c[i]--;
            s=0; j=0;
            do
              { j++; s=s+j; }
            while(s<=b[i]);
            if(s==b[i])
              r=j;
            else
              { s=s-j; j--; r=j+b[i]-s; }
            st=1; dr=j; p=1;
            out<<j<<' ';
            while(st<=dr)
              {
                 if(p==1)
                   out<<1<<' '<<r<<' ';
                 else
                   if(st==dr)
                     out<<st<<' ';
                    else
                       out<<st<<' '<<dr<<' ';
                 st++; dr--; p++;
              }
            out<<endl;
          }
     }
    in.close();
    out.close();
    return 0;
}