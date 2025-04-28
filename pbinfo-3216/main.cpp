#include <bits/stdc++.h>
#define MOD 123457
using namespace std;
int dp[10005], n;
int d[2000], k;
/// dp[i]=numarul de posibilitati de a-l scrie pe i ca suma de divizori ai lui n
void Divizori(int n)
{
    int i;
    for (i = 1; i * i < n; i++)
        if (n % i == 0)
        {
            d[++k] = i;
            d[++k] = n / i;
        }
    if (i * i == n) d[++k] = i;
    sort(d + 1, d + k + 1);
}
int main()
{
    int i, j, x;
    cin >> n;
    Divizori(n);
    /// dinamica
    for (i = 1; i <= k; i++)
    {
        x = d[i];
        dp[x]++;
        if (dp[x] == MOD) dp[x] = 0;
        for (j = 1; j <= n - x; j++)
            dp[j + x] = (dp[j + x] + dp[j]) % MOD;
    }
    cout << dp[n] << "\n";
    return 0;
}