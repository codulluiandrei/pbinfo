#include <cstdio>
#include <algorithm>
using namespace std;

const int N = (int)2e5 + 1;

int n, m;
int a[N], ti, ri;
int t[N], r[N], s;
int b[N], bl, br;

int main()
{
    freopen("report.in", "r", stdin);
    freopen("report.out", "w", stdout);
    scanf("%d%d", &n, &m), s = 0;

    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &ti, &ri);
        while (s > 0 && ri >= r[s - 1])
            --s;
        t[s] = ti, r[s] = ri, ++s;
    }

    bl = 0, br = r[0], r[s] = 0, ++s;

    for (int i = 0; i < br; ++i)
        b[i] = a[i];

    sort(b, b + br);

    for (int i = 1; i < s; ++i)
        for (int j = r[i - 1]; j > r[i]; --j)
            a[j - 1] = (t[i - 1] == 1) ? b[--br] : b[bl++];

    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);

    return 0;
}
