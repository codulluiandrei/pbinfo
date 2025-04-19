#include <fstream>
int main(void) {
  std::ifstream f("lipsa.in");
  std::ofstream g("lipsa.out");
  long long sum;
  int n, x;
  f >> n;
  sum = 0LL;
  for (int i = 1; i < n; i++) {
    f >> x;
    sum += x;
  }
  f.close();
  g << 1LL * n * (n + 1) / 2 - sum << '\n';
  g.close();
  return 0;
}