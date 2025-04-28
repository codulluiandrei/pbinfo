#include <cstdio>
#include <math.h>
using namespace std;
int maxim,n,i,j,x[1001],y[1001],poz,d1,a,b,c,k,a1,b1,c1;
short int viz[50000000];
int cmmdc(int u,int v,int w)
{
    int r,d;
    if(v<0)v=-v;
    if(w<0)w=-w;
    if(u==0)d=v;
      else if(v==0)d=u;
              else
                {
                    r=u%v;
                    while(r!=0)
                    {
                        u=v;
                        v=r;
                        r=u%v;
                    }
                    d=v;
                }
     r=w%d;
     while(r!=0)
     {
         w=d;
         d=r;
         r=w%d;
     }
     return d;
}
void brut()
{
    int max1=0;
    for(i=1;i<n;i++)
      for(j=i+1;j<=n;j++)
      {
          int nr=0;
          a=y[i]-y[j];
          b=x[j]-x[i];
          c=x[i]*y[j]-x[j]*y[i];
          for(k=1;k<=n;k++)
            if(a*x[k]+b*y[k]+c==0)nr++;
          if(nr>max1)max1=nr;
      }
      printf("%d",max1);
}
int main()
{
    freopen("coliniare.in","r",stdin);
    freopen("coliniare.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
    }
    maxim=0;
    for(i=1;i<n;i++)
      for(j=i+1;j<=n;j++)
        {
            a=y[i]-y[j];
            b=x[j]-x[i];
            c=x[i]*y[j]-x[j]*y[i];
            if(a<0){a=-a;b=-b;c=-c;}
               else if((a==0)and(b<0)){b=-b;c=-c;}
            a1=a;b1=b;c1=c;
            d1=cmmdc(a,b,c);
            a=a1/d1;b=b1/d1;c=c1/d1;
            b=b+50;
            c=c+2500;
            poz=a+b*100+c*10000;
            viz[poz]++;
            if(viz[poz]>maxim)maxim=viz[poz];
        }
     maxim=floor((sqrt(8*maxim+1)+1)/2);
     printf("%d",maxim);
     //brut();
    return 0;
}