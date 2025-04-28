#include <iostream>
#define nmax 100002
#define MOD 777013
using namespace std;
int n, dp[nmax];
int main()
{
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + 1) % MOD;
    cout << dp[n];
    return 0;
}