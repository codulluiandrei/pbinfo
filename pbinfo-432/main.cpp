#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
#define NN 205
#define INFINIT 1000000000
ifstream fin("taxe.in");
ofstream fout("taxe.out");
int n, m, a[NN][NN], s[NN][NN];
int Minim(int x , int y){
	return x<y ? x : y;
}
int Minim(int x, int y, int z)
{
	return Minim(Minim(x , y) , z);
}
int main(){
	assert(fin >> n >> m);
	for(int i=1 ; i<=n ; ++i)
		for(int j=1 ; j<=m ; j++)
			assert(fin >> a[i][j]);
	for(int i=1;i<=n;++i)
		s[i][m] = a[i][m];
	for(int j = 1 ; j <= m ; ++j)
		s[0][j] = s[n+1][j] = INFINIT;
	for(int j=m-1 ; j>=1 ; j--)
		for(int i = 1 ; i <= n ; ++i)
			s[i][j] = a[i][j] + Minim(s[i-1][j+1], s[i][j+1], s[i+1][j+1]);
	int pmin  = 1;
	for(int i = 2 ; i <= n ; ++i)
		if(s[i][1] < s[pmin][1])
			pmin = i;
	fout << s[pmin][1];
	return 0;
}