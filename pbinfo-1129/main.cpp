#include <cstdio>
#include<time.h>
int n,i,j,k,u,v,x,y,a[4][1001],b[1001][4],s;
int main()
{
	freopen("tinta.in","r",stdin);
	freopen("tinta.out","w",stdout);
	scanf("%d",&n); // citesc datele de intrare
	// generez matricea
    for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i+j<=n+1)
			{
				if((i+j)%2==0) k=(i+j-1)*(i+j-2)/2+j;
				else k=(i+j-1)*(i+j-2)/2+i;
			}
			else
			{
				u=n+1-i;
				v=n+1-j;
				if((i+j)%2==0) k=n*n+1-(u+v-1)*(u+v-2)/2-v;
				else k=n*n+1-(u+v-1)*(u+v-2)/2-u;
			}
			printf("%d ",k);
			if(i<=3 ) a[i][j]=k;
            if(j>=n-2 ) b[i][n+1-j]=k;
		}
		printf("\n");
	}
 printf("%d
",2*(n-2)-1);
 for(j=2;j<n;j++)
 { s=0;
     for(i=1;i<=3;i++)
	for(k=j-1;k<=j+1;k++)
   s+=a[i][k];
   printf("%d ",s-a[2][j]);}
   for(i=3;i<n;i++)
   {s=0;
     for(j=1;j<=3;j++)
	for(k=i-1;k<=i+1;k++)
   s+=b[k][j];
   printf("%d ",s-b[i][2]);
   }
    	return 0;
}