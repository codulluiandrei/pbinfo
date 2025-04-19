#include <cstdio>
using namespace std;
int n,i,sum,j,x,a,c,vx[11],vtot[11],cif[11],minsum,cifmax,max1,lsecv,nr1,nr2,maxsecv,nr;
int main()
{
    freopen("cifre11.in","r",stdin);
    freopen("cifre11.out","w",stdout);
    scanf("%d",&n);
    minsum=100;maxsecv=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        for(j=0;j<=9;j++)vx[j]=0;
        sum=0;
        a=x;
        while(x!=0)
        {
            c=x%10;
            vx[c]=1;
            x=x/10;
            sum+=c;
        }
        if(sum<minsum){minsum=sum;nr=a;}
                 else if((sum==minsum)&&(a>nr))nr=a;
        lsecv=0;max1=0;
        for(j=0;j<=9;j++)
           if(vx[j]>0)
               {
                   vtot[j]++;
                   lsecv++;
               }
            else {if(lsecv>max1)max1=lsecv;lsecv=0;}
        if(lsecv>max1)max1=lsecv;
        if(max1>maxsecv){maxsecv=max1;nr1=a;}
                    else if((max1==maxsecv)&&(a<nr1))nr1=a;
    }
    for(i=0;i<=9;i++)
      if(vtot[i]>cifmax){cifmax=vtot[i];nr2=1;cif[1]=i;}
         else if(vtot[i]==cifmax){nr2++;cif[nr2]=i;}
     printf("%d\n%d\n",nr,nr1);
     for(i=1;i<=nr2;i++)
       printf("%d ",cif[i]);
    return 0;
}