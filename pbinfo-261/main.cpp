#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("intervale.in");
ofstream fout("intervale.out");

int n,a[105],b[105], v[105];

int main(){
	fin >> n;
	for(int i=1;i<=n;++i)
		fin >> a[i] >> b[i];
	int k = 0;
	for(int i=1;i<=n;++i){
		int pp = 1;
		for(int j=1;j<=n;++j)
			if(i!=j)
				if(!(a[i]>b[j] || b[i]<a[j]))
					pp = 0;
		if(pp)
			v[++k] = i;
	}
	fout << k << "
";
	for(int i=1;i<=k;++i)
		fout << a[v[i]] << " " << b[v[i]] << "
";
	return 0;
}
