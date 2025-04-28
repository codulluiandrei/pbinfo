#include <bits/stdc++.h>
using namespace std;
ifstream fin("urgenta.in");
ofstream fout("urgenta.out");
struct Muchie
{
    int x, y, cost, ales;
};
Muchie a[32400];
int n, m, k, t[260], costTotal, nrm;
bool Cmp(Muchie A, Muchie B)
{
    return A.cost < B.cost;
}
void Union(int x, int y)
{
    t[x] = y;
}
int FindRoot(int x)
{
    int rad, y;
    rad = x;
    while (t[rad] != 0)
        rad = t[rad];
    while (x != rad)
    {
        y = t[x];
        t[x] = rad;
        x = y;
    }
    return rad;
}
void Citire()
{
    fin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        fin >> a[i].x >> a[i].y >> a[i].cost;
        costTotal += a[i].cost;
    }
}
void Kruskal()
{
    int x, y, costMin = 0, i, nrc = n;
    sort(a + 1, a + m + 1, Cmp);
    nrm = m;
    for (i = 1; i <= m && nrc > k; i++)
    {
        x = FindRoot(a[i].x);
        y = FindRoot(a[i].y);
        if (x != y)
        {
            costMin += a[i].cost;
            Union(x, y);
            nrc--;
            a[i].ales = 1;
            nrm--;
        }
    }
    costTotal -= costMin;
}
void Afisare()
{
    fout << costTotal << "\n";
    fout << nrm << "\n";
    for (int i = 1; i <= m; i++)
        if (a[i].ales == 0)
            fout << a[i].x << " " << a[i].y << "\n";
}
int main()
{
    Citire();
    Kruskal();
    Afisare();
    fin.close();
    fout.close();
    return 0;
}