#include <iostream>
#include <fstream>
#define NN 1005
using namespace std;
ifstream fin("difsub.in");
ofstream fout("difsub.out");
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
int sum(int x)
{
	if (x)
		return info[x] + sum(st[x]) + sum(dr[x]);
	else
		return 0;
}
int main()
{
	citire();
	int r = radacina();
	int ss = sum(st[r]), sd = sum(dr[r]);
	if(ss > sd)
		fout << ss - sd;
	else
		fout << sd - ss;
	return 0;
}