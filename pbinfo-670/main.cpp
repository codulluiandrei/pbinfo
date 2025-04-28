#include <iostream>
#include <fstream>
#define NN 1005
using namespace std;
ifstream fin("preordine.in");
ofstream fout("preordine.out");
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
void preordine(int x)
{
	if(x != 0)
	{
		fout << info[x] << " ";
		preordine(st[x]);
		preordine(dr[x]);
	}
}
int main()
{
	citire();
	int r = radacina();
	preordine(r);
	return 0;
}