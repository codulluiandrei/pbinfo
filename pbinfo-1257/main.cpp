#include <iostream>
#define MAX_N 1000
#define MOD 666013
int C[MAX_N + 1];
int catalan(int n) {
  if (C[n]) {
    return C[n];
  }
  int q = 0;
  long long tmp;
  for (int i = 0; i < n; i++) {
    tmp = q + 1LL * catalan(i) * catalan(n - i - 1);
    q = tmp % MOD;
  }
  C[n] = q;
  return q;
}
int main(void) {
  int n;
  std::cin >> n;
  C[0] = 1;
  std::cout << catalan(n) << '\n';
  return 0;
}