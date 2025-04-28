#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin ("partial.in");
ofstream fout("partial.out");
int n , a[205][205], v[205], t[205];
void dfs(int k, int tata)
{
	t[k] = tata;
	v[k] = 1;
	for(int i =1 ; i <= n ; ++i)
		if(a[k][i] == 1)
			if(v[i] == 0)
				dfs(i, k);
}
int main()
{
    int i , j , m = 0;
    fin >> n;
    while(fin >> i >> j)
    {
		a[i][j] = a[j][i] = 1;
    	m ++;
    }
    dfs(1 , 0);
    for(int i = 1 ; i <= n ; ++i)
		if(t[i] != 0)
			a[i][t[i]] = a[t[i]][i] = 2;
	int k = m;
	for(int i=1 ; i < n ; ++i)
		for(int j = i + 1 ; j <= n ; ++j)
			if(a[i][j] == 1)
				if(k > m / 2)
				{
					a[i][j] = a[j][i] = 0;
					k --;
				}
	for(int i=1 ; i <= n ; ++i)
		for(int j = 1 ; j <= n ; ++j)
			if(a[i][j] == 2)
				a[i][j] = 1;
	for(int i=1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
			fout << a[i][j] << " ";
		fout << "\n";
	}
	return 0;
}