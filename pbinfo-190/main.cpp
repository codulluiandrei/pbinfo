#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("oglindiri.in");
ofstream fout("oglindiri.out");
int n,a[1000],m;
int main(){
	fin >> n;
	for(int i=1;i<=n;++i)
		fin >> a[i];
	fin >> m;
	for( ; m ; --m){
		int i,j,aux;
		fin >> i >> j;
		assert(i<j);
		for( ; i<j; i++, j--){
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
		}
	}
	for(int i=1;i<=n;++i)
		fout << a[i] << " ";
	return 0;
}