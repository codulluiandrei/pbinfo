#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("ssume.in");
ofstream fout("ssume.out");

int n, a[101];

int main(){
	fin >> n;
	for(int i=1;i<=n;++i)
		fin >> a[i];
	for(int i=1;i<=n;++i)
		for(int j=i+1 ; j<=n ; ++j)
			if(a[i]>a[j]){
				int aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
	int c = 0, pp;
	for(int i=3 ; i<=n; ++i){
		pp = 0;
		for(int j=1 ; j<i-1 && !pp ; ++j)
			for(int k=j+1 ; k<i && !pp ; ++k)
				if(a[i] == a[j] + a[k])
					pp =1;
		if(pp)
			c++;
	}
	fout << c;
	return 0;
}
