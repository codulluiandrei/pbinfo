#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
#define NN 205
ifstream fin("cladire3.in");
ofstream fout("cladire3.out");
int n, m, a[NN][NN], s[NN][NN];
int main(){
	assert(fin >> n >> m);
	for(int i=1 ; i<=n ; ++i)
		for(int j=1 ; j<=m ; j++)
			assert(fin >> a[i][j]);
	s[n][1] = a[n][1];
	for(int i = n-1; i > 0 ; --i)
		s[i][1] = s[i+1][1] + a[i][1];
	for(int j = 2 ; j <= m ; ++j)
		s[n][j] = s[n][j-1] + a[n][j];
	for(int i = n - 1 ; i > 0 ; --i)
		for(int j = 2 ; j <= m ; ++j)
			if(s[i][j-1]<s[i+1][j])
				s[i][j] = a[i][j] + s[i][j-1];
			else
				s[i][j] = a[i][j] + s[i+1][j];
	fout << s[1][m] ;
	return 0;
}