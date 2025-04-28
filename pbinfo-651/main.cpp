#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("sumsubmax.in");
ofstream fout("sumsubmax.out");
int n , t[105], v[105] , sum[105];
void  dfs(int k)
{
	int s = 0;
	for(int i = 1 ; i <= n ; ++i)
		if(t[i] == k)
		{
			dfs(i);
			s += sum[i];
		}
	sum[k] = s + v[k];
}
int main()
{
	fin >> n;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	for(int i = 1 ; i <= n ; i ++)
		fin >> v[i];
	int r = 0 ;
	for(int i = 1 ; i <= n ; i ++)
		if(t[i] == 0)
			r = i;
	dfs(r);
	int smax = sum[1];
	for(int i = 1 ; i <= n ; ++i)
		if(smax < sum[i])
			smax = sum[i];
	for(int i = 1 ; i <= n ; ++i)
		if(smax == sum[i])
			fout << i << " ";
	return 0;
}