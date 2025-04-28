#include <fstream>
#include <queue>
using namespace std;
ifstream fin("jaina.in");
ofstream fout("jaina.out");
#define MaxN 101
#define INF 0x3f3f3f3f
int n;
int ip, jp, is, js;
int a[MaxN][MaxN];
int m;
int x, y;
struct Coord
{
	int x, y;
} source[MaxN][MaxN];
const int di[] = { -1, -1, -1, 0, 1, 1, 1,   0 };
const int dj[] = { -1,  0,  1, 1, 1, 0, -1, -1 };
queue<pair<int, int> >Q;
void Read();
void Laser_fill(int, int);
void Init();
void Lee();
bool Ok(int, int);
int main()
{
	Read();
	Lee();
	fout << a[is][js] << '\n';
	fin.close();
	fout.close();
	return 0;
}
void Read()
{
	fin >> n;
	Init();
	fin >> ip >> jp >> is >> js;
	fin >> m;
	for (int i = 1; i <= m; ++i)
	{
		fin >> x >> y;
		Laser_fill(x, y);
	}
}
void Laser_fill(int x, int y)
{
	for (int i = 1; i <= n; ++i)
	{
		a[x][i] = -1;
		if (!source[x][i].x)
			source[x][i].x = INF;
		if ( source[x][i].x > x )
			source[x][i].x = x;
		source[x][i].y = y;
		a[i][y] = -1;
		if (!source[i][y].x)
			source[i][y].x = INF;
		if ( source[i][y].x > x )
			source[i][y].x = x;
		source[i][y].y = y;
	}
	a[x][y] = INF;
}
void Init()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			a[i][j] = INF;
}
void Lee()
{
	Q.push({ ip,jp });
	a[ip][jp] = 0;
	while (!Q.empty())
	{
		int i = Q.front().first;
		int j = Q.front().second;
		Q.pop();
		for (int d = 0; d < 8; ++d)
		{
			int iv = i + di[d];
			int jv = j + dj[d];
			int x_sursa = source[iv][jv].x;
			int y_sursa = source[iv][jv].y;
			if (a[iv][jv] == -1 && a[x_sursa][y_sursa] > a[i][j] + 1)
			{
				a[x_sursa][y_sursa] = a[i][j] + 1;
				Q.push({ x_sursa, y_sursa });
			}
			else
				if (Ok(iv, jv) && a[iv][jv] > a[i][j] + 1)
				{
					a[iv][jv] = a[i][j] + 1;
					Q.push({ iv,jv });
				}
		}
	}
}
bool Ok(int i, int j)
{
	if (i < 1 || i > n || j < 1 || j > n)
		return false;
	if (a[i][j] == -1)
		return false;
	return true;
}