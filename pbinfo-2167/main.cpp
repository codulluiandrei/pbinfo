#include <queue>
#include <fstream>
#define infinit 2000000

using namespace std;

char a[205][205];
int b[205][205];
int n, xs, ys, xf, yf;
queue < pair<int, int> > q;

void Lee()
{
	int i, j, x, y, k;
	int dx[] = {1,0,-1, 0};
	int dy[] = {0,1, 0,-1};
	q.push(make_pair(xs, ys));
	b[xs][ys] = 1;
	while (!q.empty())
	{
		i = q.front().first;
		j = q.front().second;
		q.pop();
		for (k = 0; k < 4; k++)
		{
			x = i + dx[k];
			y = j + dy[k];
			if (a[x][y] != 'x' && b[x][y] > b[i][j] + 1)
			{
				b[x][y] = b[i][j] + 1;
				q.push(make_pair(x, y));
            }
        }
    }
}

void Bordare()
{
	int i;
	for (i = 0; i <= n + 1; i++)
		a[0][i] = a[n+1][i] = a[i][0] = a[i][n+1] = 'x';
}

void Citire()
{
	int i, j, y, x, m;
	ifstream fin("alee.in");
	fin >> n >> m;
	for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            a[i][j] = '.';
            b[i][j] = infinit;
        }
	for (i = 1; i <= m; i++)
    {
		fin >> x >> y;
		a[x][y] = 'x';
    }
    fin >> xs >> ys >> xf >> yf;
    fin.close();
}

void Afisare()
{
    ofstream fout("alee.out");
    fout << b[xf][yf] << "\n";
    fout.close();
}

int main()
{
	Citire();
	Bordare();
	Lee();
	Afisare();
	return 0;
}
