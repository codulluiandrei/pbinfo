#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("nivele.in");
ofstream fout("nivele.out");
int n , k, t[105];
int main()
{
	fin >> n;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	fin >> k;
	for(int i = 1 ; i <= k ; i ++)
	{
		int x , nivel = 0;
		fin >> x;
		while(x != 0)
			nivel ++, x = t[x];
		fout << nivel << "\n";
	}
	return 0;
}