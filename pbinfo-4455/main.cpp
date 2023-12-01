#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("numarare8.in");
ofstream fout("numarare8.out");

int V[1000];

int main()
{
	int n, x;
	fin >> n;
	for(int i = 1; i <= n ; i ++)
	{
		fin >> x;
		if(x >= 100 && x < 1000)	
			V[x] = 1;
	}
	int cnt = 0;
	for(int x = 100 ; x < 1000 ; x ++)
		if(V[x] == 0)
		{
			bool prim = true;
			if(x < 2)
				prim = false;
			for(int d = 2; d * d <= x ; d ++)
				if(x % d == 0)
					prim = false;
			if(prim)
				cnt ++;
		}
	fout << cnt;
	return 0;
}
