#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("subarbori.in");
ofstream fout("subarbori.out");
int n , t[105], cnt[105] ,term[105];
void dfs(int k)
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
	fin >> n;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	int r = 0;
	for(int i = 1 ; i <= n ; i ++)
		term[i] = 1;
	for(int i = 1 ; i <= n ; i ++)
		if(t[i] == 0)
			r = i;
		else
			term[t[i]] = 0;
	dfs(r);
	int nrp = 0;
	for(int i = 1 ; i < n ; ++i)
		for(int j = i + 1 ; j <= n ; ++j)
			if(!term[i] && !term[j] && cnt[i] == cnt[j])
				nrp ++;
	fout << nrp;
	return 0;
}