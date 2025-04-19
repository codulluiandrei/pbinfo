#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("maxn.in");
ofstream fout("maxn.out");
int a[305],n;
int main(){
	fin >> n;
	int Max = 0,x;
	for(int i=1;i<=n;++i){
		fin >> x;
		if(x>Max)
			Max = x;
		fout << Max << " ";
	}
	return 0;
}