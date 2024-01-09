#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("drum_hamiltonian.in");
ofstream fout("drum_hamiltonian.out");

int n , a[12][12], x[12] , p, gasit = 0;

void afis(int k)
{
	fout << "1
";
	for(int  i = 1 ; i <= k ; ++ i)
		fout << x[i] << " ";
	gasit = 1;
}

int OK(int k)
{
	if(k > 1)
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
		if( OK(k) )
			if( k == n )
				afis(k);
			else
				back(k + 1);
	}
}

int main()
{
    int i , j;
    fin >> n;
    while(fin >> i >> j)
		a[i][j] = 1;
	back(1);
	if(!gasit)
		fout << 0;
	return 0;
}
