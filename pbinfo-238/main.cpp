#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("zone.in");
ofstream fout("zone.out");
int a[305],n;
int main(){
	fin >> n;
	for(int i=1;i<=3*n;++i)
		fin >> a[i];
	int p=0 , u=0;
	for(int i=1 ; i<=n && p==0 ; ++i)
		if(a[i]%2==0)
			p = i;
	for(int i=3*n ; i>2*n && u==0 ; --i)
		if(a[i]%2==1)
			u = i;
	if(p*u){
		int aux = a[p];
		a[p] = a[u];
		a[u] = aux;
	}
	for(int i=1 ; i<=3*n ; ++i)
		fout << a[i] << " ";
	return 0;
}