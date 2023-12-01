#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

ifstream fin("puterik.in");
ofstream fout("puterik.out");

int n,k,x, v[101],m;

int main(){
	fin >> n >> k;
	m=0;
	for( ; n ; --n){
		assert(fin >> x);
		int y = x;
		while(y%k==0)
			y /= k;
		if(y==1)
			v[++m] = x;
	}
	for(int i=1;i<m;++i)
		for(int j=i+1;j<=m;++j)
			if(v[i]>v[j]){
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
	for(int i=1;i<=m;++i)
		fout << v[i] << " ";
	return 0;
}
