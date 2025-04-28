#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("subarbore1.in");
ofstream fout("subarbore1.out");
int n , k , t[105], v[105] , nf[105];
void dfs(int k)
{
	v[k] = 1;
	for(int i = 1 ; i <= n ; ++i)
		if(t[i] == k)
		{
			nf[k] = 1;
			dfs(i);
		}
}
int main()
{
	fin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	dfs(k);
	for(int i = 1 ; i <= n ; i ++)
		if(v[i] == 1 && nf[i] == 0)
			fout << i << " ";
	return 0;
}