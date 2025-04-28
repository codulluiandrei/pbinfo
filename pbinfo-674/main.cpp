#include <iostream>
#include <fstream>
#define NN 1005
using namespace std;
ifstream fin("countsub.in");
ofstream fout("countsub.out");
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
int count(int x)
{
	if (x)
		return 1 + count(st[x]) + count(dr[x]);
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