#include <bits/stdc++.h>
#define oo 2000000
using namespace std;
ifstream fin("lac.in");
ofstream fout("lac.out");
int a[105][105];
int b[105][105];
pair<int, int> urm[105][105];
int n, m;
queue < pair<int, int> > q;
int Interior(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > m)
        return 0;
    return 1;
}
void Lee()
{
    int i, j, x, y, k, cost;
    int dx[] = {1,0,-1, 0,-1, -1, 1, 1};
    int dy[] = {0,1, 0,-1, 1, -1,-1, 1};
    for (j = 1; j <= m; j++)
        q.push(make_pair(n + 1, j));
    while (!q.empty())
    {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for (k = 0; k < 8; k++)
        {
            x = i + dx[k];
            y = j + dy[k];
            cost = oo;
            if (Interior(x, y))
            {
                if (a[x][y] == 1) cost = 1;
                else cost = 0;
                if (b[x][y] > b[i][j] + cost)
                {
                    b[x][y] = b[i][j] + cost;
                    urm[x][y] = {i, j};
                    q.push(make_pair(x, y));
                }
            }
        }
    }
}
void Citire()
{
    int i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            fin >> a[i][j];
            b[i][j] = oo;
        }
    fin.close();
}
void Afisare()
{
    int k, i = 1, j = 1, x, y, M = oo;
    for (k = 1; k <= m; k++)
        if (b[1][k] < M)
        {
            M = b[1][k];
            i = 1; j = k;
        }
    fout << M << "\n";
    while (b[i][j] != 0)
    {
        x = urm[i][j].first;
        y = urm[i][j].second;
        if (b[i][j] - b[x][y] == 1)
            fout << i << " " << j << "\n";
        i = x;
        j = y;
    }
    fout.close();
}
int main()
{
    Citire();
    Lee();
    Afisare();
    return 0;
}