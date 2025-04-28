#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("frunze.in");
ofstream fout("frunze.out");
int n , t[105], v[105];
int main()
{
	fin >> n;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	int  r = 0;
	for(int i = 1 ; i <= n && r == 0 ; ++i)
		if(t[i] == 0)
			r = i;
	fout << r << "\n";
	for(int  i = 1 ; i <+ n ; ++i)
		if(t[i] != 0)
			v[t[i]] = 1;
	int k = 0;
	for(int  i = 1 ; i <= n ; ++i)
		if(v[i] == 0)
			k ++;
	fout << k << "\n";
	for(int  i = 1 ; i <= n ; ++i)
		if(v[i] == 0)
			fout << i << " ";
	return 0;
}