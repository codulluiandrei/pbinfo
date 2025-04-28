#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("afisarefii.in");
ofstream fout("afisarefii.out");
int n , k, t[105];
int main()
{
	fin >> n;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	fin >> k;
	for(int i = 1 ; i <= k ; i ++)
	{
		int x;
		fin >> x;
		int nrf = 0;
		for(int i = 1 ; i <= n ; ++i)
			if(t[i] == x)
				nrf ++;
		fout << nrf << " ";
		for(int i = 1 ; i <= n ; ++i)
			if(t[i] == x)
				fout << i << " ";
		fout << "\n";
	}
	return 0;
}