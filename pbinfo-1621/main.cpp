/*  prof. Constantin Galatan
    Solutie O(nc^2 * n^3)
 */
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
ifstream fin("miting.in");
ofstream fout("miting.out");
const int MaxN = 61, MaxC = 10, MaxV = 3601, Inf = 1 << 13,
		  di[] = { -1, 0, 1, 0}, dj[] = { 0, 1, 0, -1};
using Pair  = pair<short, short>;
short c[MaxC][MaxC][MaxV];
int  M, N, n, nc, cel[MaxN][MaxN];  // cel[i][j] = numarul de ordine corespunzator celulei (i, j)
string cuv;
deque<Pair> D;
queue<short> Q;
char H[MaxN][MaxN], ch;
inline void Lee(short i, short j);
bool Ok(short i, short j);
int main()
{
	short imin = MaxN, jmin = MaxN, imax = -1, jmax = -1, p;
	fin >> p >> N >> M >> cuv;
	fin.get();
	for (short i = 0; i < N; ++i)
	{
		fin.getline(H[i], 101);
		for (short j = 0; j < M; ++j)
		{
			ch = H[i][j];
			if ( isupper(ch) )
			{
				D.push_front({i, j});
				imin = min(imin, i); jmin = min(jmin, j);
				imax = max(imax, i); jmax = max(jmax, j);
			}
			else
				if ( ch != '#')
					D.push_back({i, j});
		}
	}
	fin.close();
	if ( p == 1 )
	{
		fout << (imax - imin + 1) * (jmax - jmin + 1) << '\n';
		fout.close();
		exit(0);
	}
	nc = cuv.size();
	vector<int> pos('Z' + 1);  // pozitiile caracterelor in cuvant
	for ( int i = 0; i < nc; ++i)
		pos[cuv[i]] = i;
	// Dupa sortare primele nc celule vor contine literele i ordinea din cuvant
	sort(D.begin(), D.begin() + nc, [&pos](const Pair& p1, const Pair& p2)
                                    { return pos[H[p1.first][p1.second]] < pos[H[p2.first][p2.second]]; }
		);
	n = D.size();
	for (int k = 0, i, j; k < n; ++k)
	{
		i = D[k].first, j = D[k].second;
		cel[i][j] = k;
	}
	for (int i = 0; i < nc; ++i)
	{
		for (int x = 0; x < n; ++x)
			for (int j = 0; j < nc; ++j)
				c[i][j][x] = Inf;
		c[i][i][i] = 0;
		Q.push(i);
		Lee(i, i);
	}
	for ( int l = 2; l <= nc; ++l)
		for (int i = 0; i < nc - l + 1; ++i)
		{
			int j = i + l - 1, cmin;
			for (int x = 0; x < n; ++x)
			{
				cmin = c[i][j][x];
				for (int k = i; k < j; ++k)
					cmin = min(cmin, c[i][k][x] + c[k + 1][j][x]);
				if ( cmin < c[i][j][x] )
					c[i][j][x] = cmin,
					Q.push(x);
			}
			if ( l < nc ) Lee(i, j);
		}
	short res = Inf;
	for (short x = 0; x < n; ++x)
		res = min(res, c[0][nc - 1][x]);
	if ( res != Inf )
        fout << res << '\n';
    else
        fout << -1 << '\n';
	fout.close();
}
inline void Lee(short i, short j)
{
	short I, J, iv, jv, x, y;
	while ( !Q.empty() )
	{
		x = Q.front();	Q.pop();
		I = D[x].first;	J = D[x].second;
		for (int dir = 0; dir < 4; ++dir )
		{
			iv = I + di[dir];
			jv = J + dj[dir];
			y = cel[iv][jv];
			if ( Ok(iv, jv) && c[i][j][y] > c[i][j][x] + 1)
			{
				c[i][j][y] = c[i][j][x] + 1;
				Q.push(y);
			}
		}
	}
}
inline bool Ok(short i, short j)
{
	if ( i < 0 || j < 0 || i >= N || j >= M ) return false;
	if ( H[i][j] == '#') return false;
	return true;
}