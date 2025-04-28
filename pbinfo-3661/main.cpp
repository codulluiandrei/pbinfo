#include <bits/stdc++.h>
#define MOD 123457
using namespace std;
int a[1003], n, p;
int A[1003];
int dp[1003][1003];
int main()
{
    int i, j, x;
    cin >> n >> p;
    /// a. dp[1]=52, dp[i] = 50 * dp[i - 1], i=2..n
    /// deci numarul este 52 * 50^(n-1)
    x = 52;
    for (i = 2; i <= n; i++)
        x = 50 * x % MOD;
    cout << x << " ";
    /** b.
    a[i] = numarul cuvintelor de lungime i care se termina cu litera mica
    A[i] = numarul cuvintelor de lungime i care se termina cu litera mare
    a[1] = A[1] = 26
    a[i] = 26 * (a[i-1] + A[i-1])
    A[i] = 26 * a[i-1]
    solutia este a[n] + A[n]
    */
    a[1] = A[1] = 26;
    for (i = 2; i <= n; i++)
    {
        a[i] = 26 * (a[i-1] + A[i-1]) % MOD;
        A[i] = 26 * a[i-1] % MOD;
    }
    x = (a[n] + A[n]) % MOD;
    cout << x << " ";
    /// c.
    dp[1][1] = 5;
    x = 21;
    for (i = 1; i <= n; i++)
    {
        dp[i][0] = x;
        x = x * 21 % MOD;
    }
    for (i = 2; i <= n; i++)
        for (j = 1; j <= i; j++)
            dp[i][j] = (21 * dp[i-1][j] + 5 * dp[i-1][j-1]) % MOD;
    x = 0;
    for (i = 0; i <= p; i++)
        x = (x + dp[n][i]) % MOD;
    cout << x << "\n";
    return 0;
}