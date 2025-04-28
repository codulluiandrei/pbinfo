#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 20;
int a[MAXN];
void max_self(int &x, const int &y) {
  if (x < y)
    x = y;
}
void min_self(int &x, const int &y) {
  if (x > y)
    x = y;
}
void add_self(int &x, const int &y) {
  x += y;
  if (x >= mod)
    x -= mod;
}
int main() {
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  int ans = 0;
  for (int mask = 1; mask < (1 << n); ++mask) {
    int mx = -INF, mn = INF;
    for (int i = 0; (1 << i) <= mask; ++i)
      if (mask & (1 << i)) {
        max_self(mx, a[i]);
        min_self(mn, a[i]);
        if (mx - mn > t)
          break;
      }
    if (mx - mn <= t)
      add_self(ans, mx - mn);
  }
  cout << ans << '\n';
  return 0;
}