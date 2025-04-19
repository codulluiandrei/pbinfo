// Copyright 2023 Ioan Popescu
#include <iostream>
#include <climits>
using std::cin;
using std::cout;
int main() {
  cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int64_t sum = 0;
  int mn = INT_MAX;
  for (int i = 0; i < n ; ++i) {
    int x;
    cin >> x;
    mn = std::min(mn, x);
    sum += x;
  }
  cout << sum - 1LL * mn * n << '\n';
  return 0;
} 