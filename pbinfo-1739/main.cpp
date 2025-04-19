#include<fstream>
using namespace std;
FILE * fin;
ofstream fout("proiecte.out");
int v[201], x[200001],Nr[201];
int n, m,cand,k;
int i,nr,j,nrmax,nrap,ok,aux;
int main()
{
	fin=fopen("proiecte.in","r");
	fscanf(fin,"%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		fscanf(fin,"%d",&nr);//fin>>nr;
		for(j=1;j<=nr;j++)
			fscanf(fin,"%d",&x[j]);
		cand=x[1];nrap=1;
        for(j=2;j<=nr;j++)		
			if(x[j]==cand)
				nrap++;
			else
				if(nrap>0)nrap--;
			    else 
				{
					nrap=1;
					cand=x[j];
				}
		if(nrap>0)
		{
			nrap=0;
			for(j=1;j<=nr;j++)		
				if(x[j]==cand)nrap++;
		}
        if(nrap>nr/2)
		{
			ok=0;
			for(j=1;j<=k;j++)
				if(v[j]==cand)
					{ 
						++Nr[j];
						ok=1;
						break;
				    }
			if(ok==0)
			{
				v[++k]=cand;
				Nr[k]=1;
			}	
		}
	}
	ok=0;
	while(!ok)
	{
		ok=1;
		for(j=1;j<=k-1;j++)
			if(v[j]>v[j+1])
				{aux=v[j];v[j]=v[j+1];v[j+1]=aux;
			     aux=Nr[j];Nr[j]=Nr[j+1];Nr[j+1]=aux;
			     ok=0;}
	}
	nrmax=Nr[1];
	for(j=2;j<=k;j++)
		if(nrmax<Nr[j])nrmax=Nr[j];
	for(j=1;j<=k;j++)
		if(nrmax==Nr[j])fout<<v[j]<<' ';
	fout<<'\n';
	fout.close();
	return 0;	
}