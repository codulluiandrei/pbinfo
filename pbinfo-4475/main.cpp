#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
ifstream fin("livada.in");
ofstream fout("livada.out");
int N, M, S;
int Sp[26][501][501], A[26][501][501];
int D[1000], k;
int cnt = 0, I, J, L, H;
bool Verif(int i,int j, int H, int L)
{
	/// verifica dacă zona cu colțul stanga-sus in (i,j), înălțime H și lățime L verifică regula
	int i1 = i + H -1, j1 = j + L - 1;
	if(i1 > N || j1 > M)
		return false;
	int v = -1;
	for(int k = 0 ; k < 26 ; k ++)
	{
		int x = Sp[k][i1][j1] - Sp[k][i-1][j1] - Sp[k][i1][j-1] + Sp[k][i-1][j-1];
		if(x > 0)
		{
			if(v == -1)
				v = x;
			else
				if(x != v)
					return false;
		}
	}
	return true;
}
int main()
{
	fin >> N >> M >> S;
	for(int i = 1; i <= S; i ++)
		if(S % i == 0)
			D[++k] = i;
	for(int i = 1; i <= N ; i ++)
		for(int j = 1; j <= M ; j ++)
		{
			char L;
			fin >> L;
			A[L - 'A'][i][j] = 1;
		}
	for(int k = 0 ; k < 26 ; k ++)
		for(int i = 1; i <= N ; i ++)
			for(int j = 1; j <= M ; j ++)
				Sp[k][i][j] = Sp[k][i-1][j] + Sp[k][i][j-1]  - Sp[k][i-1][j-1] + A[k][i][j];
	for(int i = 1; i <= N ; i ++)
		for(int j = 1; j <= M ; j ++)
			for(int p = 1 ; p <= k ; p ++)
				if(Verif(i,j,D[p], S/D[p]))
				{
					cnt ++;
					if(cnt == 1)
						I = i, J = j, H = D[p], L = S/D[p];
					//cout << i << " " << j << " " << D[p] << " " << S/D[p] << endl;
				}
	if(cnt)
	{
		fout << I << " " << J << " " << H << " " << L << '\n';
		//cout << I << " " << J << " " << H << " " << L << endl;
	}
	fout << cnt << '\n';
	//cout << cnt << endl;
	return 0;
}