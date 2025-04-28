#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e4;
int a[1 + MAXN];
void max_self(int &x, const int &y) {
  if (x < y)
    x = y;
}
void min_self(int &x, const int &y) {
  if (x > y)
    x = y;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, t;
  cin >> n >> t;
  for (int i = 1; i <= n; ++i) 
    cin >> a[i];
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int mx = -INF, mn = INF;
    for (int j = i; j <= n; ++j) {
      max_self(mx, a[j]);
      min_self(mn, a[j]);
      if (mx - mn > t)
        break;
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}