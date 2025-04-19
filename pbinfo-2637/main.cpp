#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("zoo.in");
ofstream fout("zoo.out");
const int Dim = 1001;
long long int a[Dim][Dim], n, m;
int Q;
long long int s[Dim][Dim];
int main()
{
	fin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			fin >> a[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
	int i1, j1, i2, j2;
	fin >> Q;
	while (Q--)
	{
		fin >> i1 >> j1 >> i2 >> j2;
		fout <<  s[i2][j2] - s[i1-1][j2] - s[i2][j1-1] + s[i1-1][j1-1] << '\n';
	}
    return 0;
}