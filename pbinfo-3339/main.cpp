#include <bits/stdc++.h>
using namespace std;
int t[33003], n;
int c[33003], M;
void Union(int x, int y)
{
    c[x] += c[y];
    M = max(M, c[x]);
    t[y] = x;
}
int Find(int x)
{
    int rad, y;
    rad = x;
    while (t[rad] != 0)
        rad = t[rad];
    /// comprimare drum
    while (x != rad)
    {
        y = t[x];
        t[x] = rad;
        x = y;
    }
    return rad;
}
int main()
{
    int m, i, x, y, op;
    cin >> n >> m;
    /// initializare
    for (i = 1; i <= n; i++)
        c[i] = 1;
    while (m--)
    {
        cin >> op;
        if (op == 3) cout << M << "\n";
        else /// 1 sau 2
        {
            cin >> x >> y;
            x = Find(x);
            y = Find(y);
            if (op == 1)
            {
                if (x != y) Union(x, y);
            }
            else /// op == 2
            {
                if (x == y) cout << "DA\n";
                else cout << "NU\n";
            }
        }
    }
    return 0;
}