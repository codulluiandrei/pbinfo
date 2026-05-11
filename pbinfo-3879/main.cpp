#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e18L;
const int MAXN = 3500;
const int MAXT = 1000;
int64_t dp[1 + MAXN][1 + MAXT];
void max_self(int64_t &x, const int64_t &y) {
  if (x < y)
    x = y;
}
int main() {
  int n, t, k;
  cin >> n >> t >> k;
  for (int i = 1; i <= n; ++i) {
    int hi = min(i, t);
    for (int j = 2; j <= hi; ++j)
      dp[i][j] = -INF;
  }
  int64_t ans = -INF;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    dp[i][1] = x;
    int hi = min(i, t);
    for (int j = 2; j <= hi; ++j) {
      for (int z = j - 1; z <= i - k; ++z)
        max_self(dp[i][j], dp[z][j - 1]);
      dp[i][j] += x;
    }
    if (i >= t)
      max_self(ans, dp[i][t]);
  }
  cout << ans << '\n';
  return 0;
}