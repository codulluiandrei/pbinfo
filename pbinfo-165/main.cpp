#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("maxsim.in");
ofstream fout("maxsim.out");
int n, a[1005];
int main(){
	fin >> n;
	for(int i=1;i<=n;++i)
		fin >>a[i];
	int imax =0, jmax=0;
	for(int i=1 , j=n ; i<j ; i++,j-- )
		if(a[i]+a[j] > a[imax]+a[jmax])
			imax = i, jmax = j;
	fout << a[imax] +a[jmax]<< " " << imax << " " << jmax;
	return 0;
}