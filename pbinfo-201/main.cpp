#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("submdiv.in");
ofstream fout("submdiv.out");
int n,X,x[100],v[100],m;
int nrsol;
void afis(int n){
	nrsol ++;
	for(int i=1;i<=n;++i)
		fout << v[x[i]] << " ";
	fout << "\n";
}
void back(int k){
	for(int i=x[k-1]+1;i<=n;++i){
		x[k] = i;
		if(k==m)
			afis(k);
		else
			back(k+1);
	}
}
int main(){
	fin >> X >> m;
	n = 0;
	for(int i=1;i<=X;++i)
		if(X%i==0)
			v[++n] = i;
	back(1);
	if(nrsol==0)
		fout << "fara solutie";
	return 0;
}