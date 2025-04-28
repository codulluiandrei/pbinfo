#include <fstream>
#define MAX_N 10000
int s[MAX_N];
int main(void) {
  std::fstream f("subsecv.in", std::ios::in);
  int n;
  int i, j;
  f >> n >> s[0];
  s[0] %= n;
  for (i = 1; i < n; i++) {
    f >> s[i];
    s[i] = (s[i] + s[i - 1]) % n;
  }
  f.close();
  f.open("subsecv.out", std::ios::out);
  i = 0;
  while (i < n && s[i]) {
    i++;
  }
  if (i == n) {
    i = 0;
    do {
      j = i + 1;
      while (j < n && s[i] != s[j]) {
        j++;
      }
      i++;
    } while (j == n);
    f << i + 1 << ' ' << j + 1 << '\n';
  } else {
    f << "1 " << i + 1 << '\n';
  }
  f.close();
  return 0;
}