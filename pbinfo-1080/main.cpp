//varianta optima - O(m*n)

#include<stdio.h>

int   v[700000]; 

int main()
{
	int m,n,p;
	
	FILE *fin=fopen("livada.in","r");
	FILE *fout=fopen("livada.out","w");
	
	fscanf(fin,"%d %d %d",&m,&n,&p);
	
	int max=0;
	int rsm=0;
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			fscanf(fin,"%d",&v[j]);
	
		int rmax=0;
		int j=0;
		while(j<n-1)
		{
			int k=j+1;
			while((k<n)&&(v[k]==v[j]))
				k++;
			if(k-j>rmax)
				rmax=k-j;
			j=k;
		}
		
		if(rmax>max) max=rmax;
		
		int sm=v[0];
		int cnt=1;
		
		for(int j=1;j<n;j++)
			if(cnt==0)
			{
				sm=v[j];
				cnt=1;
			}
			else
				if (v[j]==sm) cnt++;
					else cnt--;

		if(cnt==0) sm=0;
		else
		{
			cnt=0;
			for(int j=0;j<n;j++)
				if(v[j]==sm) cnt++;
			if(cnt<n/2+1) sm=0;
		}
			
		if(sm!=0) rsm++;
	}
	
	fprintf(fout,"%d
%d",rsm,max);
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}
