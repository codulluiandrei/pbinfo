#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cautaprim.in");
ofstream fout("cautaprim.out");
int n, v[100];
int main(){
	fin >> n;
	int x;
	for(int i=1;i<=n;++i){
		fin >> x;
		v[x] = 1;
	}
	int rez  = 0;
	for(x = 97 ; x>10 && rez == 0 ; x-=2)
		if(v[x]==0){
			int prim = 1;
			for(int d = 2 ; d*d<=x ; ++d)
				if(x%d == 0)
					prim = 0;
			if(prim)
				rez = x;
		}
	fout << rez;
	return 0;
}