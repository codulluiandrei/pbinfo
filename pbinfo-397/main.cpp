#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
#define NN 1005

ifstream fin("plopi1.in");
ofstream fout("plopi1.out");

int n, a[NN], L[NN];


int main(){
	assert(fin >> n );
	for(int i=1 ; i<=n ; ++i)
		assert(fin >> a[i]);
	L[n] = 1;
	for(int i=n-1 ; i>0 ; i--)
	{
		L[i] = 1;
		for(int j=i+1 ; j<=n; ++j)
			if(a[i]>a[j] && L[i]<L[j]+1)
				L[i] = L[j] + 1;
	}
	int pmax = 1;
	for(int i=1 ; i<=n ; ++i)
		if(L[pmax] <= L[i])
			pmax = i;
	fout << n - L[pmax] << endl;
	return 0;
}
