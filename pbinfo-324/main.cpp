#include <fstream>
#include <iostream>
using namespace std;
int x[1000], n, m, a[1000];
ifstream fin("partitiinumar4.in");
ofstream fout("partitiinumar4.out");
void afisare(int k){
	for(int i=1;i<=k;++i)
		fout << a[x[i]] << " ";
	fout << "\n";
}
void back(int k, int s){
	for(int i=x[k-1] ; i<=m; ++i)
	{
		x[k]=i;
		if(s+a[x[k]]<=n)
			if( s+a[x[k]] == n )
				afisare(k);
			else
				back(k+1, s+a[x[k]]);
	}
}
int main(){
	fin >> n >> m;
	for(int i=1;i<=m;++i)
		fin >> a[i];
		for(int i=1;i<m;++i)
			for(int j=i+1;j<=m;j++)
				if(a[i]>a[j]){
					int aux = a[i];
					a[i] = a[j];
					a[j] = aux;
				}
	x[0] = 1;
	back(1,0);
	return 0;
}