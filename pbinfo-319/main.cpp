#include <fstream>
#include <iostream>
using namespace std;
int x[1000], n;
ifstream fin("suma35.in");
ofstream fout("suma35.out");
void afisare(int k){
	for(int i=1;i<=k;++i)
		fout << x[i] << " ";
	fout << "\n";
}
void back(int k, int s){
	for(int i=1 ; i<=2 ; ++i)
	{
		x[k]=i==1?3:5;
		if(x[k]>=x[k-1])
			if(s+x[k]<=n)
				if( s+x[k] == n )
					afisare(k);
				else
					back(k+1, s+x[k]);
	}
}
int main(){
	fin>>n;
	back(1,0);
	return 0;
}