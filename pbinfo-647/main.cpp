#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("subarbore2.in");
ofstream fout("subarbore2.out");
int n , k , t[105], v[105] , sum[105];
void  dfs(int k)
{
	int s = v[k];
	for(int i = 1 ; i <= n ; ++i)
		if(t[i] == k)
		{
			dfs(i);
			s += sum[i];
		}
	sum[k] = s;
}
int main()
{
	fin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	for(int i = 1 ; i <= n ; i ++)
		fin >> v[i];
	dfs(k);
	fout << sum[k];
	return 0;
}