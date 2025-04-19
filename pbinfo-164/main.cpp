#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("halfsort2.in");
ofstream fout("halfsort2.out");
int n,a[1005];
int main(){
	fin >> n;
	for(int i=1; i<=n; ++i)
		fin >> a[i];
	for(int i=2;i<=n;i+=2)
		for(int j=i+2;j<=n;j+=2)
			if(a[i]>a[j]){
				int aux = a[i];
				a[i]=a[j];
				a[j]=aux;
			}
	for(int i=1;i<=n;i+=2)
		for(int j=i+2;j<=n;j+=2)
			if(a[i]<a[j]){
				int aux = a[i];
				a[i]=a[j];
				a[j]=aux;
			}
	for(int i=1;i<=n;++i)
		fout << a[i] << " ";
	return 0;
}