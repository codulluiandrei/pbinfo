#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("beculete1.in");
ofstream fout("beculete1.out");

int n, m, st[1001], dr[1001], k = 0;

int main()
{
	fin >> n >> m;
	for( ; m ; m --)
	{
		int op;
		fin >> op;
		if(op == 1)
		{
			k ++;
			fin >> st[k] >> dr[k];
		}
		else
		{
			int x, s = 0;
			fin >> x;
			for(int i = 1 ; i <= k ; i ++)
				if(x >= st[i] && x <= dr[i])
					s = 1 - s;
			if(s)
				fout << "A\n";
			else
				fout << "S\n";
		}
	}
	return 0;
}


