#include <fstream>
#include <iostream>
#include <cassert>
using namespace std;
ifstream fin("aranjamente.in");
ofstream fout("aranjamente.out");
int n , m , x[10], uz[10];
void afis(int n){
	for(int i=1 ; i<=n ; ++i)
		fout << x[i] << " ";
	fout << endl;
}
void back(int k){
	for(int i=1;i<=n;++i)
		if(uz[i]==0){
			uz[i] = 1;
			x[k]=i;
			if(k==m)
				afis(m);
			else
				back(k+1);
			uz[i] = 0;
		}
}
int main(){
	fin >> n >> m;
	back(1);
	return 0;
}