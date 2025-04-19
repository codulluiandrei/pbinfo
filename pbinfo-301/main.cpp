#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("frecventa1.in");
ofstream fout("frecventa1.out");
int n, a[100],v[100];
int main(){
	fin >> n;
	int x;
	for(int i=1;i<=n;++i){
		fin >> x;
		v[x] ++;
	}
	for(int i=0;i<100;++i)
		a[i] = i;
	for(int i=0;i<100;++i)
		for(int j=i+1;j<100;++j)
			if(v[a[i]]<v[a[j]]){
				int aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
			else
				if(v[a[i]] == v[a[j]] && a[i]>a[j]){
					int aux = a[i];
					a[i] = a[j];
					a[j] = aux;
				}
	for(int i=0;i<100;++i)
		if(v[a[i]])
			fout << a[i] << " ";
	return 0;
}