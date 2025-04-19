#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
#define NN 1005
ifstream fin("plopi2.in");
ofstream fout("plopi2.out");
int n, a[NN];
int main(){
	assert(fin >> n );
	for(int i=1 ; i<=n ; ++i)
		assert(fin >> a[i]);
	int nrp=0, L=0;
	for(int i=2 ; i<=n ; i++)
		if(a[i]>a[i-1])
			nrp++, L+= a[i]-a[i-1], a[i] = a[i-1];
	fout << nrp << " " << L << endl;
	return 0;
}