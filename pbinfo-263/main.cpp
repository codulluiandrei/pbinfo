#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("intervale2.in");
ofstream fout("intervale2.out");

int n,a[105],b[105];

int main(){
	fin >> n;
	for(int i=1;i<=n;++i)
		fin >> a[i] >> b[i];
	int maxA = a[1], minB = b[1];
	for(int i=2; i<=n ; ++i){
		if(a[i]>maxA)
			maxA = a[i];
		if(b[i]<minB)
			minB = b[i];
	}
	if(maxA > minB)
		fout << 0;
	else
		fout << maxA << " " << minB;
	return 0;
}
