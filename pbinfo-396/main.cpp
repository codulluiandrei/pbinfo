#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
#define NN 1005
ifstream fin("sclm.in");
ofstream fout("sclm.out");
int n, a[NN], L[NN], Next[NN];
int main(){
	assert(fin >> n );
	for(int i=1 ; i<=n ; ++i)
		assert(fin >> a[i]);
	L[n] = 1;
	Next[n] = -1;
	for(int i=n-1 ; i>0 ; i--)
	{
		L[i] = 1, Next[i] = -1;
		for(int j=i+1 ; j<=n; ++j)
			if(a[i]<=a[j] && L[i]<L[j]+1)
				L[i] = L[j] + 1, Next[i] = j;
	}
	int pmax = 1;
	for(int i=1 ; i<=n ; ++i)
		if(L[pmax] < L[i])
			pmax = i;
	fout << L[pmax] << endl;
	for(int i=pmax ; i!=-1 ; i = Next[i])
		fout << i << " ";
	return 0;
}