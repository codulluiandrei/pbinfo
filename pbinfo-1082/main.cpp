//Mot Nistor
/* triunghi  O(n*n)   */
#include <stdio.h>
#define M 1001
int main()
{int i,j,n,p[M];
 long long r,t,v[M],L[M];
 FILE *fi,*fo;
 fi=fopen("triunghi3.in","r");
 fo=fopen("triunghi3.out","w");
 fscanf(fi,"%d",&n);
 for(i=1;i<=n;i++)  fscanf(fi,"%d %lld",&p[i],&v[i]);
 L[1]=v[n];
 for(i=n-1;i>0;i--)
   {t=L[p[i]]; L[p[i]]=v[i];
	for(j=p[i]+1;j<=n+1-i;j++)
        {r=t-L[j-1]; t=L[j]; L[j]=r;}
	 for(j=p[i]-1;j>0;j--)
        L[j]-=L[j+1];
   }
 for(i=1;i<=n;i++)     
       fprintf(fo,"%lld ",L[i]);
 fprintf(fo,"\n"); fclose(fo);
 return 0;
}