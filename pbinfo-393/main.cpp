#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
#define NN 1005
ifstream fin("cladire1.in");
ofstream fout("cladire1.out");
int n, m, a[NN][NN], s[NN][NN];
int main(){
	assert(fin >> n >> m);
	int k, j,i;
	assert(fin >> k);
	for(int p=1 ; p<=k ; p++){
		assert(fin >> i >> j);
		if(a[i][j]){
			cout << i << " " <<j<< " se repetă la linia " << p << endl;
			exit(0);
		}
		a[i][j] = 1;
	}
	s[1][1]=1;
	for(int i=2;i<=n;++i)
		if(a[i-1][1] == 0)
			s[i][1] = s[i-1][1];
	for(int j=2 ; j<=m ; ++j)
		if(a[1][j-1] == 0)
			s[1][j] = s[1][j-1];
	for(int i=2 ; i<=n ; ++i)
		for(int j=2 ; j<=m ; ++j)
		{
			if(a[i-1][j] == 0)
				s[i][j] += s[i-1][j];
			if(a[i][j-1] == 0)
				s[i][j] += s[i][j-1];
			s[i][j] %= 9901;
		}
	fout << s[n][m];
	return 0;
}