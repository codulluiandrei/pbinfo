#include <fstream>
#define MAX_N 1000
int hist[MAX_N + 1];
int st[MAX_N], s;
inline int MAX(const int &A, const int &B) {
  return A > B ? A : B;
}
inline int solveHist(int n) {
  int maxArea = 0;
  s = 0;
  hist[n] = 0;
  for (int i = 0; i <= n; i++) {
    while ((s > 0) && (hist[st[s - 1]] > hist[i])) {
      s--;
      maxArea = MAX(maxArea, hist[st[s]] * (!s ? i : i - 1 - st[s - 1]));
    }
    st[s++] = i;
  }
  return maxArea;
}
int main(void) {
  int n, m;
  int maxArea;
  std::fstream f("plaja.in", std::ios::in);
  f.tie(0);
  std::ios_base::sync_with_stdio(0);
  f >> n >> m;
  maxArea = 0;
  for (int i = 0; i < n; i++) {
    f.get();
    for (int j = 0; j < m; j++) {
      if (f.get() == '0') {
        hist[j]++;
      } else {
        hist[j] = 0;
      }
    }
    maxArea = MAX(maxArea, solveHist(m));
  }
  f.close();
  f.open("plaja.out", std::ios::out);
  f << maxArea << '\n';
  f.close();
  return 0;
}