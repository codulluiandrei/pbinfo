#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

int n , a[105][105], v[205];

void dfs(int X)
{
	fout << X << " ";
	v[X] = 1;
	for(int i =1 ; i <= n ; ++i)
		if(a[X][i] == 1 && v[i] == 0)
			dfs(i);
}

int main()
{
    int i , j , m, X;
    fin >> n >> m >> X;
    while(m > 0)
    {
		fin >> i >> j;
    	a[i][j] = a[j][i] = 1;
    	m --;
    }
	dfs(X);
	return 0;
}
