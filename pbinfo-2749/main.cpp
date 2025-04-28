#include <bits/stdc++.h>
#define N 100005
using namespace std;
int n, rad;
int viz[N];
vector<int> h[N];
void DFS(int k)
{
    viz[k] = 1;
    for (auto i : h[k])
        if (viz[i] == 0)
            DFS(i);
}
int IsTree()
{
    DFS(rad);
    for (int i = 1; i <= n; i++)
        if (viz[i] == 0)
            return 0;
    return 1;
}
int main()
{
    int i, x, nrZ;
    cin >> n;
    nrZ = 0;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        if (x == 0)
        {
            nrZ++;
            rad = i;
        }
        else h[x].push_back(i);
    }
    if (nrZ != 1)
    {
        cout << "NU\n";
        return 0;
    }
    if (IsTree()) cout << "DA\n";
    else cout << "NU\n";
    return 0;
}