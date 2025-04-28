#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream cin("sdistante.in");
  ofstream cout("sdistante.out");
  string s; cin >> s;
  vector<long long> cnt(256, 0);
  long long ans = 0, tot = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    ans = (ans + (tot - cnt[s[i]]) * (s.size() - i)) % 1000000007;
    tot += i + 1; cnt[s[i]] += i + 1;
  }
  cout << ans << endl;
  return 0;
} 