#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

ifstream fin("eliminare2.in");
ofstream fout("eliminare2.out");

int n,a[100005], m, b[100005];

int main(){
	fin >> n;
	for(int i=1;i<=n;++i)
		fin >> a[i];
	fin >> m;
	for(int i=1;i<=m;++i)
		assert(fin >> b[i]);
	int j=1;
	for(int i=1;i<=n;++i)
		if(j<=m)
			if(a[i]==b[j])
				j++;
	if(j==m+1)
		fout << 1;
	else
		fout << 0;
	return 0;
}
