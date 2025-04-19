#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("distincte.in");
ofstream fout("distincte.out");
int main(){
	int x,y,n;
	fin >> n >> x;
	fout << x << " ";
	for(int i=2;i<=n;++i){
		fin >> y;
		if(y!=x)
			fout << y << " ";
		x = y;
	}
	return 0;
}