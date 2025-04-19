#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("sumsec.in");
ofstream fout("sumsec.out");
int n, a[1005];
int main(){
	fin >> n;
	for(int i=1;i<=n;++i)
		fin >> a[i];
	int start=0,stop=n+1 ,prim;
	do{
		start++;
		prim = 1;
		int x = a[start];
		if(x<2)
			prim = 0;
		if(x%2==0 && x>2)
			prim = 0;
		for(int d=3 ; d*d<=x ; d+=2)
			if(x%d == 0)
				prim = 0;
	}while(!prim);
	do{
		stop--;
		prim = 1;
		int x = a[stop];
		if(x<2)
			prim = 0;
		if(x%2==0 && x>2)
			prim = 0;
		for(int d=3 ; d*d<=x ; d+=2)
			if(x%d == 0)
				prim = 0;
	}while(!prim);
	cout << start << " " << stop;
	long long int s = 0;
	for(int i=start ; i<=stop ; ++i)
		s += a[i];
	fout << s;
	return 0;
}