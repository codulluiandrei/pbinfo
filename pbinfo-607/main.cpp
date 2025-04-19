#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("asfalt.in");
ofstream fout("asfalt.out");
int v[100005], n , m;
int main()
{
	fin >> n >> m;
	for(int i = 1 ; i <= m ; ++i)
	{
		int x , y;
		fin >> x >> y;
		for(int j = x + 1 ; j <= y ; j ++)
			v[j] ++;
	}
	int A = 0, B = 0;
	for(int i = 1; i <= n ; ++i)
	{
		if (v[i] == 0)
			A ++;
		if(v[i] > 1)
			B ++;
	}
	fout << A << " " << B;
	return 0;
}