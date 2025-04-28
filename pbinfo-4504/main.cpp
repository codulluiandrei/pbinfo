#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n, p, q, f[1000001];
/// f[i] = i! % MOD
long long ExpoLog(long long a, long long n)
{
    long long p;
    for (p = 1; n > 0; n /= 2)
    {
        if (n % 2 == 1)
            p = p * a % MOD;
        a = a * a % MOD;
    }
    return p;
}
int main()
{
    int i, x, X;
    cin >> n >> p >> q;
    f[0] = f[1] = 1;
    for (i = 2; i <= 1000000; i++)
        f[i] = 1LL * f[i-1] * i % MOD;
    X = 0;
    for (i = p; i <= q; i++)
    {
        x = 1LL * f[n] * ExpoLog(f[i], MOD-2) % MOD;
        x = 1LL * x * ExpoLog(f[n-i], MOD-2) % MOD;
        X += x;
        if (X >= MOD) X -= MOD;
    }
    cout << X;
    return 0;
}