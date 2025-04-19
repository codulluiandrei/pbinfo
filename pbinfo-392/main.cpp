#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
#define NN 1005
ifstream fin("cladire.in");
ofstream fout("cladire.out");
int n, m, a[NN][NN];
int main(){
	fin >> n >> m;
	for(int i=1;i<=n;++i)
		a[i][1] = 1;
	for(int j=1;j<=m;++j)
		a[1][j] = 1;
	for(int i=2;i<=n;++i)
		for(int j=2;j<=m;++j)
			a[i][j] = (a[i-1][j] + a[i][j-1]) % 9901;
	fout << a[n][m];
	return 0;
}