#include <cstdio>
#include <cassert>
#include <algorithm>
#define MAX 2000000000000000000LL
#define pii pair <long long, long long>
using namespace std;
int v[200010];
struct arb
{
    long long mipar, mapar, miimp, maimp;
    arb ()
    {
        mipar = miimp = MAX;
        mapar = maimp = 0LL;
    }
    void operator+= (const long long &val)
    {
        if (val & 1)
        {
            swap (mipar, miimp);
            swap (mapar, maimp);
        }
        if (mipar < MAX) mipar += val;
        if (miimp < MAX) miimp += val;
        if (mapar != 0LL) mapar += val;
        if (maimp != 0LL) maimp += val;
    }
} aint[800010];
long long lazy[800010];
void build (int a, int b, int nod)
{
    if (a == b)
    {
        if (v[a] & 1) aint[nod].miimp = aint[nod].maimp = 1LL * v[a];
        else aint[nod].mipar = aint[nod].mapar = 1LL * v[a];
        return;
    }
    int mij = (a + b) >> 1;
    build (a, mij, nod << 1);
    build (mij + 1, b, nod << 1 | 1);
    aint[nod].miimp = min (aint[nod << 1].miimp, aint[nod << 1 | 1].miimp);
    aint[nod].mipar = min (aint[nod << 1].mipar, aint[nod << 1 | 1].mipar);
    aint[nod].maimp = max (aint[nod << 1].maimp, aint[nod << 1 | 1].maimp);
    aint[nod].mapar = max (aint[nod << 1].mapar, aint[nod << 1 | 1].mapar);
}
void propag (int st, int dr, int nod)
{
    aint[nod] += lazy[nod];
    if (st != dr)
    {
        assert ((nod << 1 | 1) <= 800000);
        lazy[nod << 1] += lazy[nod];
        lazy[nod << 1 | 1] += lazy[nod];
    }
    lazy[nod] = 0;
}
void update (int st, int dr, int a, int b, int nod, int val)
{
    propag (st, dr, nod);
    if (a <= st && dr <= b)
    {
        lazy[nod] += 1LL * val;
        propag (st, dr, nod);
        return;
    }
    int mij = (st + dr) >> 1;
    if (a <= mij) update (st, mij, a, b, nod << 1, val);
    else propag (st, mij, nod << 1);
    if (b > mij) update (mij + 1, dr, a, b, nod << 1 | 1, val);
    else propag (mij + 1, dr, nod << 1 | 1);
    aint[nod].miimp = min (aint[nod << 1].miimp, aint[nod << 1 | 1].miimp);
    aint[nod].mipar = min (aint[nod << 1].mipar, aint[nod << 1 | 1].mipar);
    aint[nod].maimp = max (aint[nod << 1].maimp, aint[nod << 1 | 1].maimp);
    aint[nod].mapar = max (aint[nod << 1].mapar, aint[nod << 1 | 1].mapar);
}
pii query (int st, int dr, int a, int b, int nod)
{
    propag (st, dr, nod);
    if (a <= st && dr <= b) return pii(aint[nod].mipar, aint[nod].maimp);
    int mij = (st + dr) >> 1;
    pii rez1, rez2;
    rez1.first = rez2.first = MAX;
    rez1.second = rez2.second = 0;
    if (a <= mij) rez1 = query (st, mij, a, b, nod << 1);
    if (b > mij) rez2 = query (mij + 1, dr, a, b, nod << 1 | 1);
    rez1.first = min (rez1.first, rez2.first);
    rez1.second = max (rez1.second, rez2.second);
    return rez1;
}
int main ()
{
    //freopen ("input", "r", stdin);
    //freopen ("output1", "w", stdout);
    int n;
    scanf ("%d", &n);
    assert (1 <= n && n <= 200000);
    for (int i = 1; i <= n; ++i)
    {
        scanf ("%d", &v[i]);
        assert (1 <= v[i] && v[i] <= 2000000000);
    }
    build (1, n, 1);
    int q;
    scanf ("%d", &q);
    assert (1 <= q && q <= 200000);
    for (int i = 1; i <= q; ++i)
    {
        int op, a, b, val;
        scanf ("%d %d %d", &op, &a, &b);
        assert (op == 0 || op == 1);
        assert (1 <= a && a <= n);
        assert (1 <= b && b <= n);
        assert (a <= b);
        if (op == 0)
        {
            scanf ("%d", &val);
            assert (1 <= val && val <= 2000000000);
            update (1, n, a, b, 1, val);
        }
        else
        {
            pii rez = query (1, n, a, b, 1);
            assert (0LL <= rez.first && rez.first <= MAX);
            assert (0LL <= rez.second && rez.second <= MAX);
            if (rez.first >= MAX) rez.first = -1LL;
            if (rez.second == 0LL) rez.second = -1LL;
            printf ("%lld %lld\n", rez.first, rez.second);
        }
    }
    return 0;
}