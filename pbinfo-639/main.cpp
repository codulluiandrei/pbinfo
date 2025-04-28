#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("inaltime.in");
ofstream fout("inaltime.out");
int n , t[105], h[105];
void dfs(int k)
{
	for(int i = 1 ; i <= n ; i ++)
		if(t[i] == k)
		{
			h[i] = h[k] + 1;
			dfs(i);
		}
}
int main()
{
	fin >> n;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	int r = 0;
	for(int i = 1 ; i <= n && r == 0 ; i ++)
		if(t[i] == 0)
			r = i;
	h[r] = 1;
	dfs(r);
	int pmax = 1;
	for(int i = 2 ; i <= n ; i ++)
		if(h[i] > h[pmax])
			pmax = i;
	fout << h[pmax];
	return 0;
}