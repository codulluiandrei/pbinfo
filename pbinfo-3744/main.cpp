// Vlad Gavrila - 100 de puncte
#include <cstdio>
using namespace std;
#define maxn 1010
int t, g, p, cnum;
int ns, st[maxn];
const int kMaxP = 100000;
int f[kMaxP], primes[kMaxP], n_primes;
int d[kMaxP];
int main() {
    freopen("elhc.in", "r", stdin);
    freopen("elhc.out", "w", stdout);
    scanf("%d", &t);
    int ndiv_prec = 2;
    for (int i = 2; i < kMaxP; ++i) {
        if (f[i] == 0) {
            primes[++n_primes] = i;
            if (1LL * i * i >= kMaxP) {
                continue;
            }
            for (int j = i * i; j < kMaxP; j+=i) {
                f[j] = 1;
            }
        }
    }
    while(t--) {
        scanf("%d%d", &g, &p);
        if (g == 1) {
            printf("%d", p == 2);
            continue;
        }
        int x = p - 1, c = 1, ndiv = 0;
        while (primes[c] * primes[c] <= x) {
            int cp = 0;
            int ctot = 1;
            while (x % primes[c] == 0) {
                x /= primes[c];
                ++cp;
                ctot *= primes[c];
            }
            if (cp) {
                d[++ndiv] = primes[c];
            }
            ++c;
        }
        if (x > 1) {
            d[++ndiv] = x;
        }
        int ok = 1;
        for (int i = 1; i <= ndiv; ++i) {
            int a = g, r = 1, pwr = (p - 1) / d[i];
            while (pwr > 0) {
                if (pwr % 2) {
                    r = 1LL * a * r % p;
                }
                pwr /= 2;
                a = 1LL * a * a % p;
            }
            if (r == 1) {
                ok = 0;
            }
        }
        printf("%d", ok);
    }
    printf("\n");
    return 0;
} 