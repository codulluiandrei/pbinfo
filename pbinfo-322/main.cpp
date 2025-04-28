#include <fstream>
#include <iostream>
using namespace std;
int x[1000], n, m;
ifstream fin("partitiinumar2.in");
ofstream fout("partitiinumar2.out");
void afisare(int k){
	for(int i=1;i<=k;++i)
		fout << x[i] << " ";
	fout << "\n";
}
void back(int k, int s){
	for(int i=x[k-1]+1 ; i<=n-s ; ++i)
	{
		x[k]=i;
		if(s+x[k]<=n)
			if( s+x[k] == n ){
				if(k>=m)
					afisare(k);
			}
			else
				back(k+1, s+x[k]);
	}
}
int main(){
	fin >> n >> m;
	x[0]=0;
	back(1,0);
	return 0;
}