#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("nivelepare.in");
ofstream fout("nivelepare.out");
int n, t[105], nivel[105];
void dfs(int k, int nv)
{
	nivel[k] = nv;
	for(int i = 1 ; i <= n ; ++i)
		if(t[i] == k)
			dfs(i , nv + 1);
}
int main()
{
	fin >> n;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	int r = 0;
	for(int i = 1 ; i <= n ; i ++)
		if(t[i] == 0)
			r = i;
	dfs(r , 0);
	bool gata = false;
	for(int k = 0 ; !gata ; k += 2)
	{
		gata = true;
		for(int i =1 ; i <= n ; i ++)
			if(nivel[i] == k)
				fout << i << ' ', gata = false;
		if(! gata)
			fout << '\n';
	}
	return 0;
}