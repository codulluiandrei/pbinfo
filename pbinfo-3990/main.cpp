#include <iostream>
#define MOD 123457
using namespace std;
int dp[5][10002], n;
int main()
{
    int i, c;
    cin >> n;
    for (c = 1; c <= 4; c++)
        dp[c][1] = 1;
    for (i = 2; i <= n; i++)
    {
        for (c = 1; c <= 4; c++)
          dp[c][i] = (dp[1][i-1]+dp[2][i-1]+dp[3][i-1]+dp[4][i-1]-dp[c][i-1]) % MOD;
    }
    cout << (dp[2][n] + dp[4][n]) % MOD;
    return 0;
}