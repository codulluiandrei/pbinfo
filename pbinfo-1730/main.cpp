#include<stdio.h>
int a[1000005],b[1000005];
int n,i,j,r,p,k,s,t;

int main()
{
	freopen("sstabil.in","r",stdin);
	freopen("sstabil.out","w",stdout);
	scanf("%d\n",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	k=0; r=n;
	while (r>0)
	{
		j=r;  s=0;
		do
		{
			s=s+a[j];
			j--;
		}
		while (j>0 && s<10);
		k++;
		if (s<10)
		{
			b[k]=s;
			r=j;
		}
		else
		if (k==1)
			{
				p=r; t=a[p];
				while (s-t>=10)
				{
					p--;
					t=t+a[p];
				}
				b[k]=t;
				r=p-1;
			}
			else
			{
				p=r; t=a[p];
				while (s-t>9 || t+b[k-1]<10)
				{
					p--;
					t=t+a[p];
				}
				b[k]=t;
				r=p-1;
			}
	}
	for (i=k;i>=1;i--)printf("%d",b[i]);
	fclose(stdout);
	fclose(stdin);
	return 0;
}