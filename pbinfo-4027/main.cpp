#include <bits/stdc++.h>
using namespace std;
vector<int> L[100002];
int n, m, viz[100002], d[100002];
int sol[100002], len;
void Citire()
{
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        L[x].push_back(y);
    }
}
void DFS(int k)
{
    viz[k] = 1;
    for (int i : L[k])
        if (viz[i] == 0) DFS(i);
    sol[++len] = k;
}
void SortTop()
{
    for (int i = 1; i <= n; i++)
        if (viz[i] == 0) DFS(i);
}
void LongestPath()
{
    int i, k, M;
    for (i = n; i >= 1; i--)
    {
        k = sol[i];
        for (int j : L[k])
            if (d[j] < 1 + d[k])
                d[j] = 1 + d[k];
    }
    M = 0;
    for (i = 1; i <= n; i++)
        if (M < d[i]) M = d[i];
    cout << M;
}
int main()
{
    Citire();
    SortTop();
    LongestPath();
    return 0;
}