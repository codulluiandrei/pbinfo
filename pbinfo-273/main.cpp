#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("ordsume.in");
ofstream fout("ordsume.out");

int n,m, a[101], s[10001];

int main(){
	fin >> n;
	for(int i=1;i<=n;++i)
		fin >> a[i];
	m = 0;
	for(int i=1;i<n;++i)
		for(int j=i+1 ; j<=n ; j++)
			if(a[i]!=a[j])
			{
				int gasit = 0;
				for(int k=1 ; k<=m && !gasit ; ++k)
					if(s[k] == a[i]+a[j])
						gasit = 1;
				if(!gasit)
					s[++m] = a[i]+a[j];
			}
	for(int i=1;i<m;++i)
		for(int j=i+1 ; j<=m ; ++j)
			if(s[i]>s[j]){
				int aux = s[i];
				s[i] = s[j];
				s[j] = aux;
			}
	for(int i=1;i<=m;++i)
		fout << s[i] << " ";
	return 0;
}
