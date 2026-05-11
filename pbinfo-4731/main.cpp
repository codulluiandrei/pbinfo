#include<fstream>
#define inFile "dfs.in"
#define outFile "dfs.out"
using namespace std;
short a[1002][1002];
int n, m, nr, nrMuchii;
int t[1002], v[1002], viz[1002];
void Citire()
{
	int i, x, y;
	ifstream fin(inFile);
	fin >> n;
	fin	>> m;
	for (i = 1; i <= m; i++)
	{
		fin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	fin.close();
}
void DFS(int k)
{
	int i;
	t[++nr] = k;
	viz[k] = 1;
	for (i = 1; i <= n; i++)
		if (a[k][i] && !viz[i])
			DFS(i);
}
void InitV()
{
	int i, j;
	for (i = 1; i <= n; i++)
		viz[i] = 0;
	for (i = 1; i < n; i++)
		for (j = i + 1; j <= n; j++)
			a[i][j] = a[j][i] = 1;
	nr = 1;
	nrMuchii = n * (n - 1) / 2;
}
void DFS1(int k)
{
	int i;
	v[nr++] = k;
	viz[k] = 1;
	for (i = 2; i <= n; i++)
		if (a[k][i] && !viz[i])
		{
			if (i == t[nr]) DFS1(i);
			else
			{
				a[i][k] = a[k][i] = 1;
				nrMuchii--;
			}
		}
}
void Afisare()
{
	ofstream fout(outFile);
	nrMuchii -= m;
	fout << nrMuchii << "\n";
	fout.close();
}
int main()
{
	Citire();
	DFS(1);
	InitV();
	DFS1(1);
	Afisare();
	return 0;
}