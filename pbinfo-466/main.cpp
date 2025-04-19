#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("gengraf.in");
ofstream fout("gengraf.out");
int a[10][10], x[100], n , m;
void afis()
{
	for(int i=1, k = 1; i <= n ; i ++)
		for(int j = i + 1 ; j <= n ; ++j)
		{
			a[i][j] = a[j][i] = x[k];
			k ++;
		}
	for(int i = 1; i <= n ;++i)
	{
		for(int j = 1 ; j <= n ; ++j)
			fout << a[i][j] << " ";
		fout << "\n";
	}
	fout << "\n";
}
void back(int k)
{
	for(int i= 0 ; i <= 1 ; ++i)
	{
		x[k] = i;
		if(k == m)
			afis();
		else
			back(k+1);
	}
}
int main()
{
	fin >> n;
	m = n*(n-1) / 2;
	int p = 1;
	for(int i = 1 ; i <= m ; ++i)
		p *= 2;
	fout << p << "\n";
	back(1);
}