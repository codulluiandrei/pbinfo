#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin ("bipartit2.in");
ofstream fout("bipartit2.out");
int n , a[105][105], v[105] , bipartit = 1;
void dfs(int k, int x)
{
	v[k] = x;
	for(int i =1 ; i <= n ; ++i)
		if(a[k][i] == 1)
		{
			if(v[i] == 0)
				dfs(i, x == 2?1:2);
			else
				if(v[i] == x)
					bipartit = 0;
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
    dfs(1 , 1);
    if(! bipartit)
		fout << "NU";
	else{
		fout << "DA
";
		for(int i = 1 ; i <= n ; ++i)
			if(v[i] == v[1])
				fout << i << " ";
		fout << "\n";
		for(int i = 1 ; i <= n ; ++i)
			if(v[i] != v[1])
				fout << i << " ";
		fout << "\n";
	}
	return 0;
}