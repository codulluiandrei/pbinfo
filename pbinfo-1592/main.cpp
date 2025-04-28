//Dragan Andrei Gabriel
//Complexitate O(N)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, i, s1, s2, s, x[1001], y[1001];
int main()
{
    freopen("plata.in", "r", stdin);
    freopen("plata.out", "w", stdout);
    scanf("%d %d", &n, &s);
    for (s1 = s, i = 1; i <= n; i++)
        scanf("%d %d", &x[i], &y[i]), s1 -= x[i], s2 += y[i];
    if (s1 < 0 || s2 < s)
    {
        printf("imposibil\n");
        return 0;
    }
    for (s = s1, i = 1; i <= n; i++)
    {
        if (y[i] - x[i] <= s && s > 0)
            printf("%d ", y[i]), s -= (y[i] - x[i]); else
            if (y[i] - x[i] > s && s > 0)
                printf("%d ",s + x[i]), s=0; else
                if (s == 0) printf("%d ", x[i]);
    }
    return 0;
}