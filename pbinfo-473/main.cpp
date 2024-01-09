#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("bipartitcomplet.in");
ofstream fout("bipartitcomplet.out");

int n , a[105][105], x[105] , k;


int main()
{
    fin >> n >> k;
    for(int i = 1 ; i <= k ;++i)
	{
		int p;
		fin >> p;
		x[p] = 1;
	}
    for(int i = 1; i <= n ; i++)
		for(int j = 1 ; j <= n ; ++j)
			if(x[i] != x[j])
				a[i][j] = a[j][i] = 1;
	for(int i = 1; i <= n ; i++){
		for(int j = 1 ; j <= n ; ++j)
			fout << a[i][j] << " ";
		fout << endl;
	}
	return 0;
}
