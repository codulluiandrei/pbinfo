#include <fstream>
#include <iostream>
#include <cassert>

using namespace std;

ifstream fin("siruri.in");
ofstream fout("siruri.out");

int n , m , x[16];

int minim(int x,int y){
	if(x<y)
		return x;
	return y;
}

void afis(int n){
	for(int i=1 ; i<=n ; ++i)
		fout << x[i] << " ";
	fout << endl;
}

void back(int k){
	for(int i=((k==1)?1:x[k-1]+1);i<=((k==1)?n:minim(n,x[k-1]+2));++i)
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

