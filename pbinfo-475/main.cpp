#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("lant.in");
ofstream fout("lant.out");
int n , a[105][105], x[205] , p , q;
void afis(int k)
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
void back(int k)
{
	for(int i = 1  ; i <= n ; ++i)
	{
		x[k] = i;
		if(OK(k))
		{
			if(x[k] == q)
				afis(k);
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
	return 0;
}