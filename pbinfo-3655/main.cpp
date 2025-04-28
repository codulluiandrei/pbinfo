#include <bits/stdc++.h>
using namespace std;
int dp[105][105], n, m;
char s[105], t[105];
int main()
{
    int i, j;
    cin >> (s + 1) >> (t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    /// initializare coloana 0
    for (i = 1; i <= n; i++)
        dp[i][0] = i;
    /// initializare linia 0
    for (j = 1; j <= m; j++)
        dp[0][j] = j;
    /// top-down:
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        dp[i][j] = min({1+dp[i-1][j], 1+dp[i][j-1], dp[i-1][j-1] + (s[i] != t[j])});
    cout << dp[n][m] << "\n";
    return 0;
}