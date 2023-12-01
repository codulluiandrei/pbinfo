#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

ifstream fin("divk.in");
ofstream fout("divk.out");

int n,k,x;

int main(){
	fin >> n >> k;
	for( ; n ; --n){
		assert(fin >> x);
		int s = 0, d;
		for(d=1; d*d < x ;d++)
			if(x%d==0)
				s +=2;
		if(d*d==x)
			s ++;
		if(s >= k)
			fout << x << " ";
	}

	return 0;
}
