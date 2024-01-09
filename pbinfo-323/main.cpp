#include <fstream>
#include <iostream>
using namespace std;

int x[1000], n, a, b;

ifstream fin("partitiinumar3.in");
ofstream fout("partitiinumar3.out");

int minim(int x, int y){
	return x<y ? x : y;
}

void afisare(int k){
	for(int i=1;i<=k;++i)
		fout << x[i] << " ";
	fout << "
";
}

void back(int k, int s){
	for(int i=x[k-1] ; i<= minim(n-s,b) ; ++i)
	{
		x[k]=i;
		if(s+x[k]<=n)
			if( s+x[k] == n )
				afisare(k);
			else
				back(k+1, s+x[k]);
	}
}
int main(){

	fin >> n >> a >> b;
	x[0] = a;
	back(1,0);
	return 0;
}
