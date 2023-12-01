#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("unice1.in");
ofstream fout("unice1.out");

int n , v[1005],uz[1005];

int main(){
	fin >> n;
	for(int i=1 ; i<=n ; ++i)
		fin >> v[i], uz[i] = 0;
	int C = 0;
	for(int i=1 ; i<=n ; ++i)
		if(uz[i] == 0)
		{
			int cc = 1;
			for(int j=i+1;j<=n;++j)
				if(uz[j] == 0 && v[j] == v[i])
					cc ++, uz[j] = 1;
			if(cc == 1)
				C ++;
		}
	fout << C;
	return 0;
}
