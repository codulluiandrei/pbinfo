#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("veriflant.in");
ofstream fout("veriflant.out");

int n , a[105][105], x[205] , k , p;

int main()
{
    int i , j , m;
    fin >> n >> m;
    while(m > 0)
    {
		fin >> i >> j;
    	a[i][j] = a[j][i] = 1;
    	m --;
    }
	fin >> k;
	for( ; k ; k --)
	{
		fin >> p;
		for(int i = 1 ; i <= p ; ++i)
		{
			fin >> x[i];
		}
		int  ok  = 1;
		for(int i = 1 ; i < p ; ++i)
			if(a[x[i]][x[i+1]] == 0)
			{
				ok = 0;
			}
		if(! ok)
			fout << "NU
";
		else
		{
			for(int i = 1; i < p ; ++i)
				for(int j = i + 1 ; j <= p ; ++ j)
					if(x[i] == x[j])
						ok = 0;
			if(ok)
				fout << "ELEMENTAR
";
			else
				fout << "NEELEMENTAR
";
		}
	}
	return 0;
}
