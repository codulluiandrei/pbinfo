#include <bits/stdc++.h>
using namespace std;
ifstream f ("bitsir.in");
ofstream g ("bitsir.out");
typedef long long LL;
constexpr int NMAX = 1e5 + 5;
constexpr int MOD = 1e9 + 7;
int N;
LL X, Y;
LL Mask[NMAX];
int fact[NMAX];
int inv_fact[NMAX];
int LgPut (int a, int b) {
    if (b == 1) return a;
    if (b == 0) return 1;
    int val = LgPut(a, b/2);
    val = (1LL * val * val) % MOD;
    if (b % 2 == 1) return (1LL * val * a) % MOD;
    return val;
}
void Precalculare () {
    fact[0] = 1;
    for (int i = 1; i <= N; ++ i )
        fact[i] = (1LL * fact[i-1] * i) % MOD;
    inv_fact[N] = LgPut(fact[N], MOD-2);
    for (int i = N - 1; i >= 0; -- i )
        inv_fact[i] = (1LL * inv_fact[i+1] * (i + 1)) % MOD;
}
int Comb (int n, int k) {
    int ans = (1LL * inv_fact[k] * inv_fact[n - k]) % MOD;
    return (1LL * ans * fact[n]) % MOD;
}
int main () {
    f >> N >> X >> Y;
    for (int i = 1; i <= N; ++ i )
        f >> Mask[i];
    if (Y > X) {
        g << "NU\n" << 0;
        return 0;
    }
    Precalculare();
    int answer = 1;
    for (int b = 0; (1LL<<b) <= X; ++ b ) {
        if ((X&(1LL<<b)) == 0) {
            for (int i = 1; i <= N; ++ i ) {
                if ((Mask[i] & (1LL<<b))) {
                    g << "NU\n" << 0;
                    return 0;
                }
            }
            if ((Y&(1LL<<b))) {
                g << "NU\n" << 0;
                return 0;
            }
            continue;
        }
        int start = 0;
        if ((Y&(1LL<<b))) start = 1;
        int cnt_forced_one = 0;
        for (int i = 1; i <= N; ++ i ) {
            if ((Mask[i]&(1LL<<b)))
                cnt_forced_one ++;
        }
        if (cnt_forced_one % 2 == 1)
            start = (1 - start);
        int n = N - cnt_forced_one;
        bool exists_one = (cnt_forced_one > 0);
        if (!exists_one && start == 0) start += 2;
        int coef = 0;
        for (int i = start; i <= n; i += 2)
            coef = (1LL * coef + 1LL * Comb(n, i)) % MOD;
        if (coef == 0) {
            g << "NU\n" << 0;
            return 0;
        }
        answer = (1LL * answer * coef) % MOD;
    }
    g << "DA\n" << answer;
    return 0;
}