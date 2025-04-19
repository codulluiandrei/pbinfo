//Sursa: Cosmin-Dumitru Oprea
#include <cstdio>
#include <algorithm>
#include <vector>
#define TMax 200000
#define KMax 100000
long long ans;
int vx[TMax+1], vy[TMax+1], n, t, k;
struct Elem {
    int pos;
    int x;
    long long val;
} Q[KMax+1];
bool cmp_pos(const Elem &A, const Elem &B)
{
    return A.pos < B.pos;
}
bool cmp_x(const Elem &A, const Elem &B)
{
    return A.x < B.x;
}
struct comparer
{
    bool operator ()(Elem const& p, int const i) const
    {
        return p.x < i;
    }
};
inline void add(int poz, int val)
{
    if (poz == 0)
        poz = n;
    std::lower_bound(Q + 1, Q + k + 1, poz, comparer())->val += val;
}
void read()
{
    scanf("%d %d %d", &n, &t, &k);
    for (int i = 1; i <= t; ++i) {
        scanf("%d %d", vx + i, vy + i);
    }
    for (int i = 1; i <= k; ++i){
        scanf("%d", &Q[i].x);
        Q[i].pos = i;
		Q[i].val = 0;
    }
}
void build_solution()
{
    std::sort(Q + 1, Q + k + 1, cmp_x);
    for (int i = 1; i <= t; ++i) {
        int x = vx[i];
        int y = vy[i];
        if (y >= n) {
            ans += 1LL * y / n;
            y = y % n;
        }
		if (y == 0) {
			continue;
		}
        add(x, 1);
        if (x + y - 1 <= n)
        {
            add(x + y, -1);
        }
        else
        {
            add(1, 1);
            add(x + y - n, -1);
        }
    }
    for (int i = 1; i <= k; ++i) {
        Q[i].val += Q[i - 1].val;
    }
}
void print_solution()
{
    std::sort(Q + 1, Q + k + 1, cmp_pos);
    for (int i = 1; i <= k; ++i) {
        printf("%lld ", ans + Q[i].val);
    }
}
int main()
{
    freopen("mere.in", "r", stdin);
    freopen("mere.out", "w", stdout);
    read();
    build_solution();
    print_solution();
    return 0;
}