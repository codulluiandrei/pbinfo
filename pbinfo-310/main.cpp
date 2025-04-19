#include <iomanip>
#include <fstream>
#include <iostream>
#include <cassert>
using namespace std;
ifstream fin("secvpal.in");
ofstream fout("secvpal.out");
int main(){
	int p, u, n;
	int a[1005], SMax = -1;
	fin >> n;
	for(int i=1 ; i<=n ; i++)
		fin >> a[i];
	p = 1, u = 0;
	SMax = -1;
	for(int i=1 ; i<=n ; i++){
		int j=i,k=i;
		while(j>0 && k<=n && a[j] == a[k])
			j--, k++;
		if(k-j-1 > u-p+1)
			p = j+1, u = k-1;
		j=i , k=i+1;
		while(j>0 && k<=n && a[j] == a[k])
			j--, k++;
		if(k-j-1 > u-p+1)
			p = j+1, u = k-1;
	}
	fout << p << " " << u;
	return 0;
}