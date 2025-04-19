#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("interval1.in");
ofstream fout("interval1.out");
int n, k, a[1005];
int main(){
	fin >> n >> k;
	for(int i=1;i<=n;++i)
		fin >> a[i];
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
				if(a[i]>a[j]){
					int aux = a[i];
					a[i] = a[j];
					a[j] = aux;
				}
	int aa=a[1],bb=a[k];
	for(int i=1;i<=n-k+1;++i)
		if(a[i+k-1]-a[i]<bb-aa)
			aa = a[i], bb = a[i+k-1];
	fout << aa << " " << bb;
	return 0;
}