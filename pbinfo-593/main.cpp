#include <iostream>
#include <fstream>
#define INFINIT 1000000000
using namespace std;
ifstream fin("parc.in");
ofstream fout("parc.out");
int n , a[105][105], v[105], d[105];
int main()
{
    int i , j , C, m, cost;
    fin >> n >> m >> C;
    for(i =1 ; i <= n ; ++i){
		for(j = 1 ; j <= n ; ++j)
			a[i][j] = INFINIT;
		a[i][i] = 0;
	}
    while( m )
    {
		fin >> i >> j >> cost;
    	a[i][j] = a[j][i] = cost;
    	m --;
	}
	for(i =1 ; i <= n ; i ++ )
	{
		v[i] = 0;
		d[i] = a[C][i];
	}
	v[C] = 1 , d[C] = 0;
	d[0] = INFINIT;
	for(int k = 1 ; k < n ; ++k)
	{
		int pmax = 0;
		for(i = 1 ; i <= n ; ++i)
			if(v[i] == 0 && d[i] < d[pmax])
				pmax = i;
		if(pmax > -1)
		{
			v[pmax] = 1;
			for(i = 1; i <= n ; ++i)
				if(v[i] == 0 && d[i] > d[pmax] + a[pmax][i])
					d[i] = d[pmax] + a[pmax][i];
		}
	}
	int p, x, sol = 0;
	fin >> p;
	for(int i = 1; i <= p ; ++i)
	{
		fin >> x;
		if(d[x] < d[sol])
			sol = x;
		else
			if(d[x] == d[sol])
				if(x < sol)
					sol = x;
	}
	fout << sol << endl;
    return 0;
}