#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("lantmaxim.in");
ofstream fout("lantmaxim.out");
int n , a[105][105], x[105] , p , q, xmax[105], kmax = 0;
void afis(int x[], int k)
{
	for(int  i = 1 ; i <= k ; ++ i)
		fout << x[i] << " ";
	fout << "\n";
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
void verifica(int k)
{
	if(k > kmax)
	{
		kmax = k;
		for(int i = 1; i <= k ; ++i)
			xmax[i] = x[i];
	}
}
void back(int k)
{
	for(int i = 1  ; i <= n ; ++i)
	{
		x[k] = i;
		if(OK(k))
		{
			if(x[k] == q)
				verifica(k);
			else
				back(k + 1);
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
	assert(fin >> p >> q);
	x[1] = p;
	back(2);
	afis(xmax , kmax);
	return 0;
}