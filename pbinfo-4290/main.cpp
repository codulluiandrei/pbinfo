#include <bits/stdc++.h>
using namespace std;
int a[105][105], n, m, viz[105], pred[105];
void Citire()
{
    int i, j, k;
    cin >> n >> m;
    assert(1 <= n && n <= 100);
    for (k = 1; k <= m; k++)
    {
        cin >> i >> j;
        assert(1 <= i && i <= n);
        assert(1 <= j && j <= n);
        assert(i != j);
        a[i][j] = a[j][i] = 1;
    }
}
void Afis(int k, int i)
{
    cout << i << " ";
    while (k != i)
    {
        cout << k << " ";
        k = pred[k];
    }
    cout << i << "\n";
    exit(0);
}
void DFS(int k)
{
    viz[k] = 1;
    for (int i = 1; i <= n; i++)
        if (a[k][i] == 1)
        {
            if (viz[i] == 0)
            {
                pred[i] = k;
                DFS(i);
            }
            else
            {
                if (i != pred[k])
                    Afis(k, i);
            }
        }
}
void Rezolva()
{
    for (int i = 1; i <= n; i++)
        if (viz[i] == 0) DFS(i);
}
int main()
{
    Citire();
    Rezolva();
    return 0;
}