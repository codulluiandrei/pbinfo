#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
#define NN 205

ifstream fin("cladire2.in");
ofstream fout("cladire2.out");

int n, m, a[NN][NN], s[NN][NN];


int main(){
	assert(fin >> n >> m);
	for(int i=1 ; i<=n ; ++i)
		for(int j=1 ; j<=m ; j++)
			assert(fin >> a[i][j]);
	s[1][1] = a[1][1];
	for(int i=2;i<=n;++i)
		s[i][1] = s[i-1][1] + a[i][1];
	for(int j=2 ; j<=m ; ++j)
		s[1][j] = s[1][j-1] + a[1][j];
	for(int i=2 ; i<=n ; ++i)
		for(int j=2 ; j<=m ; ++j)
			if(s[i-1][j] > s[i][j-1])
				s[i][j] = s[i-1][j] + a[i][j];
			else
				s[i][j] = s[i][j-1] + a[i][j];
	
	fout << s[n][m] << "
";
	
	int L[2*NN], C[2*NN], p = n+m-1;
	L[p] = n, C[p] = m;
	for( ; p>1 ; p--){
		int i = L[p], j = C[p];
			
		if( s[i][j] == a[i][j]+s[i-1][j])
			L[p-1] = i-1, C[p-1] = j;
		else
			L[p-1] = i, C[p-1] = j-1;
			
	}
	
	for(p=1 ; p<=n+m-1 ; p++)
		fout << L[p] << " " << C[p] << "
";
	
	return 0;
}
