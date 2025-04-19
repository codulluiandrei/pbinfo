#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("prime4.in");
ofstream fout("prime4.out");
int V[1000];
int main()
{
	int n, x;
	fin >> n;
	for(int i = 1; i <= n ; i ++)
	{
		fin >> x;
		bool prim = true;
		if(x < 2)
			prim = false;
		for(int d = 2; d * d <= x ; d ++)
			if(x % d == 0)
				prim = false;
		if(prim)
			V[x] ++;
	}
	int rez = 1;
	for(int x = 100 ; x < 1000 ; x ++)
		if(V[x] > V[rez])
			rez = x;
	fout << rez;
	return 0;
}