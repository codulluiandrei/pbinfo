#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MOD = 1e9 + 7;
int main() {
  ifstream cin("primar.in");
  ofstream cout("primar.out");
  int n; cin >> n;
  vector<pair<int, int>> v(n);
  set<int> sx, sy;
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second;
    assert(v[i].first > 0 && v[i].first <= 1000000);
    assert(v[i].second > 0 && v[i].second <= 1000000);
    assert(!sx.count(v[i].first));
    sx.insert(v[i].first);
    assert(!sy.count(v[i].second));
    sy.insert(v[i].second);
  }
  sort(v.begin(), v.end());
  long long ans = 0;
  int cnt = 0;
  int lu = -1, ld = -1, lr = -1, ll = -1;
  for (int i = 0; i < n; ++i) {
    int yu = INF, yd = -INF, xl = v[i].first, yl = v[i].second;
    for (int j = i + 1; j < n; ++j) {
      int x = v[j].first, y = v[j].second;
      // check j = right point
      if (yu > y && yd < y && yu < INF && yd > -INF) {
        int xr = x;
        if (lu == yu && ld == yd && lr == xr && ll == xl) 
          continue;
        ans = (ans + 1LL * (xr - xl - 1) * (yu - yd - 1)) % MOD;
        lu = yu; ld = yd; lr = xr; ll = xl;
        cnt += 1;
      }
      // update up, down
      if (y > yl) yu = min(yu, y);
      else yd = max(yd, y);
    }
  }
  cout << ans << endl;
  cerr << ans << " " << cnt << endl;
  return 0;
} 