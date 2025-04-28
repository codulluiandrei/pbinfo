#include <bits/stdc++.h>
#define nmax 30003
using namespace std;
vector<int> L[nmax];
int n, d[nmax];
int X, Y, viz[nmax];
void Citire()
{
    int i, j;
    cin >> n;
    while (cin >> i >> j)
    {
        L[i].push_back(j);
        L[j].push_back(i);
    }
}
void DFS(int k, int tata)
{
    viz[k] = 1;
    for (auto i : L[k])
        if (viz[i] == 0) DFS(i, k);
        else if (i != tata)
        {
            X = i; Y = k;
        }
}
void Sterge(int x, int y)
{
    unsigned int len = L[x].size();
    for (unsigned int i = 0; i < len; i++)
        if (L[x][i] == y)
        {
            L[x][i] = L[x][len - 1];
            L[x].pop_back();
            return;
        }
}
void BFS()
{
    int k;
    /// sterge muchia (X, Y)
    Sterge(X, Y);
    Sterge(Y, X);
    queue <int> q;
    q.push(X);
    d[X] = 1;
    while (!q.empty())
    {
        k = q.front();
        q.pop();
        for (auto i : L[k])
            if (d[i] == 0)
            {
                d[i] = 1 + d[k];
                q.push(i);
            }
    }
    cout << d[Y] << "\n";
}
int main()
{
    Citire();
    DFS(1, 0);
    BFS();
    return 0;
}