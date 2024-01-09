#include <fstream>
#include <iostream>
using namespace std;

int x[1000], n;

ifstream fin("partitiinumar1.in");
ofstream fout("partitiinumar1.out");

void afisare(int k){
	for(int i=1;i<=k;++i)
		fout << x[i] << " ";
	fout << "
";
}

void back(int k, int s){
	for(int i=x[k-1]+1 ; i<=n-s ; ++i)
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
	x[0]=0;
	back(1,0);
	return 0;
}
