#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
#define NN 205
ifstream fin("comori.in");
ofstream fout("comori.out");
int n, m, a[NN][NN], s[NN][NN];
int Maxim(int x , int y){
	return x>y ? x : y;
}
int Maxim(int x, int y, int z)
{
	return Maxim(Maxim(x , y) , z);
}
int Maxim(int * v, int * u)
{
	int M = *v;
	for( v++; v!=u; v++)
		M = Maxim(M,*v);
	return M;
}
int main(){
	assert(fin >> n >> m);
	for(int i=1 ; i<=n ; ++i)
		for(int j=1 ; j<=m ; j++)
			assert(fin >> a[i][j]);
	for(int j=1;j<=m;++j)
		s[1][j] = a[1][j];
	for(int i=2; i<=n;++i){
		s[i][1] = a[i][1] + Maxim(s[i-1][1], s[i-1][2]);
		s[i][m] = a[i][m] + Maxim(s[i-1][m-1],s[i-1][m]);
		for(int j=2 ; j<m ; ++j)
			s[i][j] = a[i][j] + Maxim(s[i-1][j-1] , s[i-1][j] , s[i-1][j+1]);
	}
	fout << Maxim(s[n]+1, s[n]+m+1) ;
	return 0;
}