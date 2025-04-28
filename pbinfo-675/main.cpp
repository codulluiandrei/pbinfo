#include <iostream>
#include <fstream>
#define NN 1005
using namespace std;
ifstream fin("bifrunze.in");
ofstream fout("bifrunze.out");
int n, info[NN], st[NN], dr[NN];
int frunza[NN];
void citire()
{
	fin >> n;
	for(int i =1 ; i <= n ; ++i)
		fin >> info[i] >> st[i] >> dr[i];
}
int main()
{
	citire();
	for(int i = 1 ; i <= n ; i ++)
		frunza[i] = 0;
	for(int i = 1 ; i <= n ; i ++)
		if(st[i] == 0 && dr[i] == 0)
			frunza[i] = 1;
	for(int i = 1 ; i <= n ; ++i)
		if(frunza[i])
			fout << i << " ";
	return 0;
}