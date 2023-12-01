#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("secvcresc.in");
ofstream fout("secvcresc.out");

int n, a[10005];

int main(){
	fin >> n;
	for(int i=1;i<=n;++i)
		if(!(fin >> a[i]))
		{
				cout << i;
				return 1;
		}
	int st=1, dr = 0;
	for(int i=1;i<=n;++i){
		int j=i+1;
		while(j<=n && a[j]>a[j-1])
			j++;
		if(j-i>dr-st+1)
			st=i,dr=j-1;
		i=j-1;
	}
	fout << st << " " << dr;
	return 0;
}
