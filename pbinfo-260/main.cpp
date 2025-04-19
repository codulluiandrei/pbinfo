#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
ifstream fin("lungime.in");
ofstream fout("lungime.out");
int v[100005],n;
int main(){
	fin >> n;
	for(int i=1;i<=n;++i)
		fin >> v[i];
	int lgmax = 0;
	for(int x = 1;x<100;++x){
		int p=0,u=0;
		for(int i=1; i<=n && p==0; ++i)
			if(v[i]==x)
				p = i;
		for(int i = n; i>0 && u==0 ; --i)
			if(v[i]==x)
				u = i;
		if(p)
			if(u-p+1>lgmax)
				lgmax = u-p+1;
	}
	fout << lgmax ;
	return 0;
}