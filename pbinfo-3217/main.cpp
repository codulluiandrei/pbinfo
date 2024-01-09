/// Solutie - Moca Andrei - 100p
#include <bits/stdc++.h>
using namespace std;
const int mod = 9001;
int n, k, j, res;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	cin >> n >> k;
	vector<short> dp(n + 1);
	dp[1] = 1;
	for (int i = 2; i < n; i++)
    {
        j = min(k, i - 1);
        dp[i] = (2 * dp[i - 1] - dp[i - j - 1]) % mod;
        while (dp[i] > mod)
            dp[i] -= mod;
        if (dp[i] < 0)
            dp[i] += mod;
    }
    j = min(k, n - 1);
    res = dp[n - 1] - dp[n - j - 1];
    if (res < 0)
        res += mod;
	cout << res;
	return 0;
}