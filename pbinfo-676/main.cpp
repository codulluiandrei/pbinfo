#include <iostream>
#include <fstream>
#define NN 1005
using namespace std;
ifstream fin("countprimsub.in");
ofstream fout("countprimsub.out");
int n, info[NN], st[NN], dr[NN];
void citire()
{
	fin >> n;
	for(int i =1 ; i <= n ; ++i)
		fin >> info[i] >> st[i] >> dr[i];
}
int radacina()
{
	int v[NN];
	for(int i =1 ; i <= n ; ++i)
		v[i] = 0;
	for(int i = 1 ; i <= n ; ++i)
	{
		if(st[i] != 0)
			v[st[i]] = 1;
		if(dr[i] != 0)
			v[dr[i]] = 1;
	}
	for(int i = 1 ; i <= n ; ++i)
		if(v[i] == 0)
			return i;
	return 0;
}
bool prim(int n)
{
	if(n < 2)
		return false;
	if(n > 2 && n % 2 == 0)
		return false;
	for(int d = 3 ; d * d <= n ; d += 2)
		if(n % d == 0)
			return false;
	return true;
}
int count(int x)
{
	if (x)
		if(prim(info[x]))
			return 1 + count(st[x]) + count(dr[x]);
		else
			return count(st[x]) + count(dr[x]);
	else
		return 0;
}
int main()
{
	citire();
	int k , x;
	fin >> k;
	for(int i = 1 ; i <= k ; i ++)
	{
		fin >> x;
		fout << count(x)<< endl;
	}
	return 0;
}