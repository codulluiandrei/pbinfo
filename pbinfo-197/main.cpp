#include <fstream>
#include <iostream>
#include <cassert>

using namespace std;

ifstream fin("combinari.in");
ofstream fout("combinari.out");

int n , m , x[10];

void afis(int n){
	for(int i=1 ; i<=n ; ++i)
		fout << x[i] << " ";
	fout << endl;
}

void back(int k){
	for(int i=x[k-1]+1;i<=n;++i)
	{
		x[k]=i;
		if(k==m)
			afis(m);
		else
			back(k+1);
	}
}

int main(){
	fin >> n >> m;
	back(1);
	return 0;
}

