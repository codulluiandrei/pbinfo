#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("knivel.in");
ofstream fout("knivel.out");
int n , k, t[105], nivel[105];
void dfs(int k, int nv)
{
	nivel[k] = nv;
	for(int i = 1 ; i <= n ; ++i)
		if(t[i] == k)
			dfs(i , nv + 1);
}
int main()
{
	fin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	int r = 0;
	for(int i = 1 ; i <= n ; i ++)
		if(t[i] == 0)
			r = i;
	dfs(r , 1);
	for(int i = 1 ; i <= n ; i ++)
		if(nivel[i] == k)
			fout << i << " ";
	return 0;
}