#include <fstream>
#include <iostream>
using namespace std;

int x[11], xmax[11], uz[11], a[11] ,n , smax;

ifstream fin("cerc.in");
ofstream fout("cerc.out");

void back(int k){
	for(int i=1 ; i<=n ; ++i)
	if(uz[i]==0)
	{
		uz[i]=1;
		x[k]=i;
		if(k==n){
			int s = a[x[n]]*a[x[1]];
			for( int j=1;j<n;j++)
				s += a[x[j]]*a[x[j+1]];
			if(s>smax){
				smax = s;
				for(int j=1; j<=n;++j)
					xmax[j]=x[j];
			}
		}
		else
			back(k+1);
		uz[i]=0;
	}
}
int main(){

	fin>>n;
	for(int i=1;i<=n;++i)
		fin >> a[i];
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
			if(a[i]>a[j]){
				int aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
	x[1]=1, uz[1] = 1;
	back(2);
	for(int i=1;i<=n;++i)
		fout << a[xmax[i]] << " ";
	return 0;
}
