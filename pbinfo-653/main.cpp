#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("firma1.in");
ofstream fout("firma1.out");
int n , t[105], salariu[105] , castig[105];
void  dfs(int k)
{
	int s = 0, cnt = 0;
	for(int i = 1 ; i <= n ; ++i)
		if(t[i] == k)
		{
			dfs(i), cnt ++;
			s += castig[i];
		}
	if(cnt > 0)
	{
		if(s % cnt == 0)
			s /= cnt;
		else
			s = (int)(s/cnt) + 1;
	}
	castig[k] = s + salariu[k];
}
int main()
{
	fin >> n;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	for(int i = 1 ; i <= n ; i ++)
		fin >> salariu[i];
	int r = 0 ;
	for(int i = 1 ; i <= n ; i ++)
		if(t[i] == 0)
			r = i;
	dfs(r);
	fout << castig[r];
	return 0;
}