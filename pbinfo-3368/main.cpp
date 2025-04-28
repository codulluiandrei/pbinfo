#include <bits/stdc++.h>
#define nmax 1505
#define oo 1e9
using namespace std;
struct Element
{
    int cost, x, y;
    bool operator<(const Element &A) const
    {
        return cost > A.cost;
    }
};
int a[nmax][nmax], n;
int d[nmax][nmax];
priority_queue <Element> q;
void Citire()
{
    int X, Y, Z, T, i, j;
    cin >> n >> X >> Y >> Z >> T;
    for (int i = 1; i <= n; i++)
        cin >> a[1][i];
    for (i = 2; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = 1 + (a[i-1][j-1] * X + a[i-1][j] * Y + a[i-1][j+1] * Z) % T;
}
inline bool Interior(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > n)
        return false;
    return true;
}
void Lee()
{
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    int i, j, x, y, k;
    Element w;
    /// init
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            d[i][j] = oo;
    w.x = w.y = 1;
    w.cost = a[1][1];
    q.push(w);
    d[1][1] = a[1][1];
    while (!q.empty())
    {
        i = q.top().x;
        j = q.top().y;
        q.pop();
        for (k = 0; k < 4; k++)
        {
            x = i + dx[k];
            y = j + dy[k];
            if (Interior(x, y) && d[x][y] > a[x][y] + d[i][j])
            {
                w.cost = d[x][y] = a[x][y] + d[i][j];
                w.x = x;
                w.y = y;
                q.push(w);
            }
        }
    }
    cout << d[n][n] << "\n";
}
int main()
{
    Citire();
    Lee();
    return 0;
}