#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("hamilton.in");
ofstream fout("hamilton.out");

int n , a[12][12], x[12] , p, gasit = 0;

void afis(int k)
{
	fout << "1
";
	for(int  i = 1 ; i <= k ; ++ i)
		fout << x[i] << " ";
	fout << x[1] << "
";
	gasit = 1;
}

int OK(int k)
{
	if(a[x[k-1]][x[k]] != 1)
		return 0;
	for(int i = 1 ; i < k ; ++i)
		if( x[k] == x[i] )
			return 0;
	return 1;
}

void back(int k)
{
	for(int i = 1  ; i <= n && ! gasit ; ++i)
	{
		x[k] = i;
		if(OK(k))
		{
			if( k == n )
			{
				if(a[x[k]][x[1]] == 1)
					afis(k);
			}
			else
				back(k + 1);
		}
	}
}

int main()
{
    int i , j;
    fin >> n;
    while(fin >> i >> j)
    {
		a[i][j] = a[j][i] = 1;
    }
	x[1] = 1;
	back(2);
	if(!gasit)
		fout << 0;
	return 0;
}
