#include <iostream>
int i,a,b,c,d,x,y,solx[30000],soly[30000],solz[30000],k,nr,r,j,a1,b1,t,k1,ok,poz,xx;
using namespace std;
void brut()
{
    int u,z,v,q;
    q=20000;
    cout<<"\n\n metoda bruta";
   for(i=2;i<=q;i++)
     for(j=i;j<=q;j++)
       {
           u=b*i*j;
           v=a*i*j-b*i-b*j;
           if(v!=0)
           if((u%v==0)&&(v>0))
             {
                 z=u/v;
                 if(z<i)cout<<z<<" "<<i<<" "<<j<<"\n";
                   else if(z<j)cout<<i<<" "<<z<<" "<<j<<"\n";
                          else cout<<i<<" "<<j<<" "<<z<<"\n";
             }
       }//lipseste ordonarea solutiilor si eliminarea duplicatelor
}
int main()
{
    cin>>a>>b;
    x=a;
    y=b;
    while(x%y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    a=a/y; b=b/y;
    i=b/a+1;
    j=(3*b)/a;
    for(x=i;x<=j;x++)
    {
       c=a*x-b;
       d=b*x;
       while(c%d!=0)
       {
         r=c%d;
         c=d;
         d=r;
       }
       a1=(a*x-b)/d;
       b1=(b*x)/d;
       for(k=1;k<=b1;k++)
       {
           if((b1*b1)%k==0)
              {
               if (((b1+k)%a1==0)and(x<=((b1+k)/a1)and(x<=(b1*(b1+k)/a1)/k)))
                  {nr++;
                   solx[nr]=x;
                   solz[nr]=(b1+k)/a1;
                   soly[nr]=(b1*solz[nr])/k;
                         t=solz[nr];
                         solz[nr]=soly[nr];
                         soly[nr]=t;
                  }
              }
       }
    }
    poz=nr;
    do{
       ok=1;
      for(i=1;i<=poz-1;i++)
        if((solx[i]>solx[i+1])or((solx[i]==solx[i+1])&&(soly[i]>soly[i+1])))
          {
               t=solx[i];
               solx[i]=solx[i+1];
               solx[i+1]=t;
               t=soly[i];
               soly[i]=soly[i+1];
               soly[i+1]=t;
               t=solz[i];
               solz[i]=solz[i+1];
               solz[i+1]=t;
               ok=0;
               xx=i;
          }
          poz=x;
    }while(ok==0);
    if(nr>0)
        for(i=1;i<=nr;i++) cout<<solx[i]<<" "<<soly[i]<<" "<<solz[i]<<"\n";
     else cout<<"NU ARE SOLUTII";
   // brut();
    return 0;
}