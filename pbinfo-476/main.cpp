#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("lanturi.in");
ofstream fout("lanturi.out");

int n , a[105][105], x[205] , p , q , r;

void afis(int k)
{
	for(int  i = 1 ; i <= k ; ++ i)
		fout << x[i] << " ";
	fout << "
";
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

void back(int k , int pus_r)
{
	for(int i = 1  ; i <= n ; ++i)
	{
		x[k] = i;
		if(OK(k))
		{
			if(x[k] == r)
				pus_r = 1;
			if(x[k] == q)
			{
				if( pus_r )
					afis(k);
			}
			else
				back(k + 1, pus_r);
			if(x[k] == r)
				pus_r = 0;
		}
	}
}

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
	assert(fin >> p >> q >> r);
	x[1] = p;
	back(2 , 0);
	return 0;
}
