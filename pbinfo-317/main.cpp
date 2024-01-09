#include <fstream>
#include <iostream>
using namespace std;

int x[11], uz[11], a[11][11] ,n , smax;

ifstream fin("summax.in");
ofstream fout("summax.out");

void back(int k){
	for(int i=1 ; i<=n ; ++i)
	if(uz[i]==0)
	{
		uz[i]=1;
		x[k]=i;
		if(k==n){
			int s = 0;
			for( int j=1;j<=n;j++)
				s += a[j][x[j]];
			if(s>smax){
				smax = s;
			}
		}
		else
			back(k+1);
		uz[i]=0;
	}
}
int main(){

	fin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			fin >> a[i][j];
	back(1);
	fout << smax;
	return 0;
}
