#include <bits/stdc++.h>
#define nmax 100005
#define mmax 500005
using namespace std;
int t[nmax], n, m;
pair<int, int> M[mmax];
int answer[mmax];
/// returneaza nodul radacina din componenta conexa
/// din care face parte nodul x
inline int Find(int x)
{
    int rad, y;
    rad = x;
    while (t[rad] != 0) rad = t[rad];
    while (x != rad)
    {
        y = t[x];
        t[x] = rad;
        x = y;
    }
    return rad;
}
/// unifica componentele conexe care au ca radacini
/// nodurile x si y
inline void Union(int x, int y)
{
    t[y] = x;
}
int main()
{
    int i, x, y, nrCompCon;
    cin >> n >> m;
    for (i = 1; i <= m; i++)
    {
        cin >> x >> y;
        M[i] = make_pair(x, y);
    }
    nrCompCon = n;
    for (i = m; i >= 1; i--)
    {
        answer[i] = nrCompCon;
        x = Find(M[i].first);
        y = Find(M[i].second);
        if (x != y)
        {
            Union(x, y);
            nrCompCon--;
        }
    }
    /// afisare
    for (i = 1; i <= m; i++)
        cout << answer[i] << "\n";
    return 0;
}