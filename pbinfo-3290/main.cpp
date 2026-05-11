// 100 p - implementare Dan Pracsiu
#include<fstream>
#define inFile "matd3.in"
#define outFile "matd3.out"
using namespace std;
int a[255][255], L, C, b[255][255], sol;
void Citire()
{
	int i, j, x;
	ifstream fin(inFile);
	fin >> L >> C;
	for (i = 1; i <= L; i++)
		for (j = 1; j <= C; j++)
		{
			fin >> x;
			x = x % 3;
			a[i][j] = x;
			b[i][j] = b[i-1][j] + x;
		}
	fin.close();
}
inline int NumarDiv3(int z, int u, int d)
{
	int k;
	k = z * (z + 1) / 2;
	if (u > 0) k = k + u * (u - 1) / 2;
	if (d > 0) k = k + d * (d - 1) / 2;
	return k;
}
void Calcul()
{
	int i, j, k, zero, unu, doi, x, s;
	sol = 0;
	for (i = 1; i <= L; i++)
		for (j = i; j <= L; j++)
		{
			zero = unu = doi = s = 0;
			for (k = 1; k <= C; k++)
			{
				x = (b[j][k] - b[i-1][k]) % 3;
				s = (s + x) % 3;
				if (s == 0) zero++;
				else if (s == 1) unu++;
				else doi++;
			}
			sol += NumarDiv3(zero, unu, doi);
		}
}
void Afisare()
{
	ofstream fout(outFile);
	fout << sol << "\n";
	fout.close();
}
int main()
{
	Citire();
	Calcul();
	Afisare();
	return 0;
}