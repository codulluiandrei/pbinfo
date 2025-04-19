#include <fstream>
using namespace std;
ifstream fin("dmax.in");
ofstream fout("dmax.out");
int n,a[105][105],v[105],d[105],q[105];
int main(){
	int m,st=1,dr=0;
	fin >> n >> m;
	for( ; m ; --m){
		int i, j;
		fin >> i >> j;
		a[i][j] = a[j][i] = 1;
	}
	q[++dr] = 1;
	v[1] = 0;
	d[1] = 0;
	while(st <= dr){
		int k = q[st];
		for(int i=1;i<=n;++i)
			if(v[i]==0 && a[k][i]==1){
				q[++dr] = i;
				v[i] = 1;
				d[i] = d[k] + 1;
			}
		++st;
	}
	int p = 1;
	for(int i=1;i<=n; ++i)
		if(d[i]>d[p])
			p = i;
	fout << p << "\n";
	return 0;
}