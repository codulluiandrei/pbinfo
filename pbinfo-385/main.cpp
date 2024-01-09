#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
#define NN 105

ifstream fin("sumtri.in");
ofstream fout("sumtri.out");

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
			if(S[i-1][j-1]>S[i-1][j])
				S[i][j] = S[i-1][j-1] + a[i][j];
			else
				S[i][j] = S[i-1][j] + a[i][j];
	}
	int pmax = 1;
	for(int i = 2 ; i <= n ;++i)
		if(S[n][i]>S[n][pmax])
			pmax = i;
	fout << S[n][pmax];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j)
			cout << S[i][j] << " ";
		cout << endl;
	}
	return 0;
}
