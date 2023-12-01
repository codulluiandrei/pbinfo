//Popa Bogdan Ioan, Colegiul National Aurel Vlaicu Orastie, clasa a 10-a
#include <bits/stdc++.h>
#define nmax 100002
#define ll long long
using namespace std;
ifstream fin("op.in");
ofstream fout("op.out");
int n;
int a[nmax];
int i;
ll K;
int t;
bool ok;
ll unesc(int a, int b)
{
    int p = log10(b) + 1;
    ll p10 = 1;
    while(p--)
        p10 *= 10;
    return (ll)a * p10 + b;
}
ll cnt(ll val, bool &ok)
{
    int i, j;
    ll ret = 0;
    for(i = 1, j = n; i <= n; i++)
    {
        while(j >= 1 && unesc(a[i], a[j]) > val)
            j--;
        if(!j)
            return ret;
        ret += j;
        if(unesc(a[i], a[j]) == val)
            ok = 1;
    }
    return ret;
}
ll rez(ll K)
{
    ll s = unesc(a[1], a[1]), d = unesc(a[n], a[n]), m = 0, best = 0;
    bool ok;
    while(s <= d)
    {
        m = (s + d) / 2;
        ok = 0;
        ll F = cnt(m, ok);
        if(F >= K)
        {
            if(ok)
            {
                if(F == K)
                    return m;
                best = m;
            }
            d = m - 1;
        }
        else s = m + 1;
    }
    return best;
}
int main()
{
    fin >> t >> n >> K;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    sort(a + 1, a + n + 1);
    if(t == 1)
        fout << cnt(K, ok) << "\n";
    else
        fout << rez(K) << "\n";
    return 0;
}
