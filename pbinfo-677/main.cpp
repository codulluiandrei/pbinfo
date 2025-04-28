#include <iostream>
#include <fstream>
#define NN 1005
using namespace std;
ifstream fin("nivelebin.in");
ofstream fout("nivelebin.out");
int n, info[NN], st[NN], dr[NN];
int v[NN], nv;
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
void parcurgere(int x, int niv)
{
	if (x)
	{
		v[niv]++;
		if(niv > nv)
			nv = niv;
		parcurgere(st[x] , niv + 1);
		parcurgere(dr[x] , niv + 1);
	}
}
int main()
{
	citire();
	parcurgere(radacina() , 0);
	fout << nv + 1 << endl;
	for(int i = 0 ; i <= nv ; i ++)
		fout << v[i] << " ";
	return 0;
}