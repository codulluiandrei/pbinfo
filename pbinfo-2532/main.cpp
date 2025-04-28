#include <bits/stdc++.h>
#define Nmax 1005
#define md 666013
using namespace std;
int dp[Nmax][9 * Nmax];
int N, S;
int main()
{
    cin >> N >> S;
    for(int i = 1; i <= 9; i++)
        dp[1][i] = 1;
    for(int i = 2; i <= N; i++)
        for(int j = 1; j <= min(9 * i, S); j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][max(j - 10, 0)] + md) % md;
    cout << dp[N][S] << "\n";
    return 0;
}