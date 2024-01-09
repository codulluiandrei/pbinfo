#include <fstream>
#include <iostream>
using namespace std;

int x[1000], n;

ifstream fin("partitiinumar.in");
ofstream fout("partitiinumar.out");

void afisare(int k){
	for(int i=1;i<=k;++i)
		fout << x[i] << " ";
	fout << "
";
}

void back(int k, int s){
	for(int i=x[k-1] ; i<=n-s ; ++i)
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

	fin>>n;
	x[0]=1;
	back(1,0);
	return 0;
}
