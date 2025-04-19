#include<bits/stdc++.h>
#define DIM 100010
using namespace std;
ifstream fin("cmmp.in");
ofstream fout("cmmp.out");
unsigned long long i,j,k,pp,x,cif,nr,n,v[DIM],f[DIM];
int main() {
	for (i=1;pp<100000;i++) { //precalculam toate subsecventele de cifre care apar
		x=1LL*i*i;			  //in primele 100000 de patrate perfecte
		cif=0;
		while (x!=0) {
			v[++cif]=x%10;
			x/=10;
		}
		for (j=cif;j>0;j--) {
			nr=0; //in nr vom avea toate subsecventele de cifre ale lui x(i^2)
			for (k=j;k>=1&&j-k+1<=5;k--) {
				nr=nr*10+v[k];
				if (f[nr]==0) { //in f[nr] vom avea cel mai mic numar care
					f[nr]=i;	//ridicat la patrat il va contine pe nr
					pp++;
				}
			}
		}
	}
	f[0]=0; //din precalculare era 100
	fin>>n;
	for (i=1;i<=n;i++) {
		fin>>x;
		fout<<1LL*f[x]*f[x]<<" ";
	}
	return 0;
}