#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, n, k, nr, t, i, r;
    ifstream f("sirdivk.in");
    ofstream g("sirdivk.out");
    f >> a >> b >> c >> n >> k;
    nr = t = 0;
    for(i = 1; i <= n; i++)
    {
        r = i % 3;
        if (r == 1) r = a;
        else if(r == 2) r = b;
        else r = c;
        t = (t * 10 + r) % k;
        if (t == 0) nr++;
    }
    g << nr << "\n";
    g.close();
    f.close();
    return 0;
 }