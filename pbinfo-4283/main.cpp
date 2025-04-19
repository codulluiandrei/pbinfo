#include <bits/stdc++.h>
using namespace std;
int n, k, i, x, dr, st, v[11005];
long long s, maxx = LLONG_MIN;
ifstream f("lowmem1.in");
ofstream g("lowmem1.out");
int main()
{
    f >> k;
    for(i = 0; i < k; i ++)
    {
        f >> v[i];
        s = s + v[i];
    }
    maxx = s;
    while(f >> x)
    {
        s = s + x - v[i % k];
        v[i % k] = x;
        if(s > maxx) maxx = s, dr = i;
        i ++;
    }
    st = dr - k + 1;
    g << maxx << "\n";
    f.close();
    ifstream f("lowmem1.in");
    f >> k;
    i = 0;
    while(f >> x)
    {
        if(i >= st && i <= dr) g << x << " ";
        i ++;
        if(i > dr) return 0;
    }
    return 0;
}