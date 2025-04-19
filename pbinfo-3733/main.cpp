/// Ioan Cristian Pop
#include <cstdio> 
#include <algorithm> 
using namespace std; 
const int NMAX = 1000000; 
int f[NMAX + 1]; 
int main() 
{ 
    freopen("cosuri.in", "r", stdin); 
    freopen("cosuri.out", "w", stdout); 
    int n, s, x, y, t, mn, mx, mn2, mx2, diff; 
    bool ok = 1; 
    scanf("%d%d", &t, &n); 
    if (t == 1) { 
        scanf("%d %d", &x, &y); 
        mn = mx2 = min(x, y); 
        mx = mn2 = max(x, y); 
        for (int i = 3; i <= 2 * n; ++i) { 
            scanf("%d", &x); 
            if (x < mn) { 
                mn2 = mn; 
                mn = x; 
            } else if (x < mn2) { 
                mn2 = x; 
            } 
            if (x > mx) { 
                mx2 = mx; 
                mx = x; 
            } else if (x > mx2) { 
                mx2 = x; 
            } 
        } 
        printf("%d %d\n", mn + mn2, mx + mx2); 
        return 0; 
    } 
    scanf("%d", &x); 
    mn = mx = x; 
    ++f[x]; 
    for (int i = 2; i <= 2 * n; ++i) { 
        scanf("%d", &x); 
        ++f[x]; 
        if (mn > x) { 
            mn = x; 
        } 
        if (mx < x) { 
            mx = x; 
        } 
    } 
    s = mn + mx; 
    for (int i = 1; i <= (s + 1) / 2; ++i) { 
        if (f[i] != f[s - i]) { 
            ok = 0; 
            break; 
        } 
        if (f[i] > 0) { 
            diff = (s - i) - i; 
        } 
    } 
    if (ok == 0) { 
        printf("NU\n"); 
    } else { 
        printf("DA\n%d\n", diff); 
    } 
    return 0; 
} 