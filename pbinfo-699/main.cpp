/*
    sol Eugen Nodea - cautare binara
*/
# include <cstdio>
# include <algorithm>
# define NMax 100003
using namespace std;
struct interval
{
    int a, b;
} v[NMax];
int i, N, P;
long long s, d, m;
bool cmp (interval x, interval y)
{
    if (x.a > y.a) return false;
    return true;
}
inline int intersectie(interval x, interval y, long long m)
{
    if ((x.b + m < y.a - m )|| (y.b + m < x.a - m)) return 0;
    return 1;
}
bool este (long long x)
{
    int i, nr = 1;
    for (i = 1; i<N; ++i)
    {
        if (intersectie(v[i], v[i+1], x))
        {
            ++nr;
            if (nr >= P) return true;
        }
        else nr = 1;
    }
    return false;
}
int main()
{
    freopen ("intervale3.in", "r", stdin);
    freopen ("intervale3.out", "w", stdout);
    scanf("%d %d", &N, &P);
    for (i=1; i<=N; ++i)
        scanf("%d %d", &v[i].a, &v[i].b);
    sort(v + 1, v + N + 1, cmp);
    s = 1; d = 1500000000;
    while (s <= d)
    {
        m = s + ((d - s) >> 1);
        if (este(m)) d = m - 1;
                else s = m + 1;
    }
    printf("%lld
", s);
    return 0;
}