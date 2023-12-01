#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("binar.in");
ofstream fout("binar.out");
long long n,nr, x[10001],i,j,cifra,numar,k;
int y[10001],aparitii[10001],h,aux;
int main()
{
    fin>>n>>nr;
	numar=0;k=0;
    for(i=1;i<=n;i++)
    { 
		fin>>cifra;
        if (cifra==-1)
        { 
			k++;
			x[k]=numar;
            numar=0;
        }
        else numar=numar*2+cifra;
    }
    //for (i=1;i<=k;i++) cout<<x[i]<<" ";
	for(i=1;i<=k-1;i++)
		for(j=i+1;j<=k;j++)
			if(x[i]<x[j])
			{
				aux=x[i];
				x[i]=x[j];
				x[j]=aux;
			}
    h=1;
    for(i=1;i<=k-1;i++)
		if(x[i]==x[i+1])
			aparitii[h]++;
		else
		{
			y[h]=x[i];
			aparitii[h]++;
			h++;
		}
	y[h]=x[k];
	aparitii[h]++;
	for(i=1;i<=h-1;i++)
		for(j=i+1;j<=h;j++)
			if(aparitii[i]<aparitii[j]||((aparitii[i]==aparitii[j])&&(y[i]<y[j])))
			{
				aux=y[i];
				y[i]=y[j];
				y[j]=aux;
				aux=aparitii[i];
				aparitii[i]=aparitii[j];
				aparitii[j]=aux;
			}
	for(i=1;i<=nr;i++)
		fout<<y[i]<<" "<<aparitii[i]<<'\n';
	fin.close();
	fout.close();
    return 0;
}
