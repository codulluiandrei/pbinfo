#include <bits/stdc++.h>
using namespace std;
ifstream f("sort_div.in");
ofstream g("sort_div.out");
int prima(int x)
{
    while (x > 9) x /= 10;
    return x;
}
int NrDiv(int x)
{
    int P = 1, d = 2, p;
    while (x > 1)
    {
        p = 0;
        while (x % d == 0)
        {
            x /= d;
            p++;
        }
        P *= (p + 1);
        if (d == 2) d = 3;
        else d += 2;
        if (d * d > x && x > 1) d = x;
    }
    return P;
}
struct nr
{
    int val, div, con, cif;
}
v[16384];
bool fcmp(nr a, nr b)
{
    if (a.div < b.div) return true;
    else if (a.div == b.div && a.con < b.con) return true;
    else if (a.div == b.div && a.con == b.con && a.cif < b.cif) return true;
    else if (a.div == b.div && a.con == b.con && a.cif == b.cif && a.val < b.val) return true;
    else return false;
}
int n, i;
int main()
{
    f >> n;
    for (i = 1; i <= n; i++)
    {
        f >> v[i].val;
        v[i].div = NrDiv(v[i].val);
        v[i].con = v[i].val % 9;
        if(v[i].con == 0) v[i].con = 9;
        v[i].cif = prima(v[i].val);
    }
    sort(v + 1, v + n + 1, fcmp);
    for (i = 1; i <= n; i++) g << v[i].val << " ";
    f.close();
    g.close();
    return 0;
}