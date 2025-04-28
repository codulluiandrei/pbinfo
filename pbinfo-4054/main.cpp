// Soluție Bogdan Vlad-Mihai, clasa a XII-a, Liceul Teoretic "Aurel Vlaicu" Orăștie
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll l; cin >> l;
  int n; cin >> n;
  vector<ll> v(n);
  for (ll &x : v)
    cin >> x;
  multiset<ll> lengths;
  set<ll> points;
  lengths.insert(-(l + 1));
  points.insert((ll)0);
  points.insert(l);
  for (ll x : v) {
    auto lowerLimit = points.lower_bound(x);
    lowerLimit--;
    auto low = *lowerLimit, up = *points.upper_bound(x);
    lengths.erase(lengths.find(-(up - low + 1)));
    lengths.insert(-(up - x + 1));
    lengths.insert(-(x - low + 1));
    points.insert(x);
    cout << -(*lengths.begin()) << "\n";
  }
  return 0;
}