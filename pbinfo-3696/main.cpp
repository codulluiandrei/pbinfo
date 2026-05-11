#include <fstream>
#include <queue>
using namespace std;
ifstream fin("taxa.in");
ofstream fout("taxa.out");
struct nod{ int a,b;};
#define CMAX 40010
const short dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const short dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
short d[1010][1010];
short c[1010][1010];
int N, M, ii, xx;
nod p1, p2, bb, w, t;
queue<nod> Q[CMAX];
inline short prod(short A, short B)
{
	if (A == B) return 0;
	return A * B;
}
inline bool este(short i, short j)
{
	if (1 <= i && i <= N && 1 <= j && j <= M) return true;
	return false;
}
inline void Fill(short i, short j, short cost)
{
	if (este(i, j) && c[i][j] == -1)
	{
		if (d[i][j] == xx)
		{
			c[i][j] = cost;
			for (int k = 0; k < 8; k++)
				Fill(i + dx[k], j + dy[k], cost);
		}
		else
			bb.a = i, bb.b = j, Q[cost + prod(d[i][j], xx)].push(bb);
	}
}
int main()
{
	fin >> N >> M >> p1.a >> p1.b >> p2.a >> p2.b;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			fin >> d[i][j], c[i][j] = -1;
	Q[0].push(p1);
	for (ii = 0; ii < CMAX; ii++)
	{
		for (; !Q[ii].empty(); Q[ii].pop())
		{
            w = Q[ii].front(); xx = d[w.a][w.b];
			if (c[w.a][w.b] == -1)
				Fill(w.a, w.b, ii);
			if (c[p2.a][p2.b] != -1)
			{
				fout << c[p2.a][p2.b] << '\n';
				fout.close();
				return 0;
			}
		}
	}
	return 0;
}