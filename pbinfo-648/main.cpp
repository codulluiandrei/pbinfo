#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("subarborenumarare.in");
ofstream fout("subarborenumarare.out");
int n , k , t[105], cnt[105];
void  dfs(int k)
{
	int s = 0;
	for(int i = 1 ; i <= n ; ++i)
		if(t[i] == k)
		{
			dfs(i);
			s += cnt[i];
		}
	cnt[k] = s + 1;
}
int main()
{
	fin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	dfs(k);
	fout << cnt[k];
	return 0;
}