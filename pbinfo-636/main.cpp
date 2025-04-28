#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("arbore.in");
ofstream fout("arbore.out");
int n , k , a[105][105], t[105], v[105];
void dfs(int k , int tata)
{
	v[k] = 1, t[k] = tata;
	for(int i = 1 ; i <= n ; ++i)
		if(v[i] == 0 && a[k][i] == 1)
			dfs(i , k);
}
int main()
{
	fin >> n >> k;
	for(int p = 1 ; p < n ; p ++)
	{
		int i , j;
		fin >> i >> j;
		a[i][j] = a[j][i] = 1;
	}
	dfs(k , 0);
	for(int i = 1 ; i <= n ; ++i)
		fout << t[i] << " ";
	return 0;
}