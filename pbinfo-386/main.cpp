#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
#define NN 105

ifstream fin("sumtri1.in");
ofstream fout("sumtri1.out");

int n, a[NN][NN], S[NN][NN];


int main(){
	fin >> n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			assert(fin >> a[i][j]);
	S[1][1] = a[1][1];
	for(int i=2 ; i<=n ; ++i){
		S[i][1] = S[i-1][1]+a[i][1];
		S[i][i] = S[i-1][i-1]+ a[i][i];
		for(int j=2 ; j < i ; ++j)
			if(S[i-1][j-1]<S[i-1][j])
				S[i][j] = S[i-1][j-1] + a[i][j];
			else
				S[i][j] = S[i-1][j] + a[i][j];
	}
	int pmin = 1;
	for(int i = 2 ; i <= n ;++i)
		if(S[n][i]<S[n][pmin])
			pmin = i;
	fout << S[n][pmin] << endl;
	int v[NN];
	v[n] = pmin;
	for(int i=n-1;i>0;--i)
	{
		if(S[i+1][v[i+1]]==a[i+1][v[i+1]]+S[i][v[i+1]])
			v[i] = v[i+1];
		else
			v[i] = v[i+1]-1;
	}
	for(int i=1;i<=n;++i)
		fout << a[i][v[i]] << " ";
	return 0;
}
