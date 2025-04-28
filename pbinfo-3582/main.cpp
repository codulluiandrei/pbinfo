#include <fstream>
using namespace std;
ifstream fin ("sotron1.in");
ofstream fout ("sotron1.out");
int N, ans, a[256][256];
int main () {
  fin >> N;
  for (int i = 1; i <= N; i ++)
    for (int j = 1; j <= N; j ++)
      fin >> a[i][j];
  for (int i = 1; i <= N; i ++)
    for (int j = N; j > 0; j --) {
      if ((i + j) & 1) {
        if (a[i][j + 1] > 0)
          a[i][j] += a[i][j + 1];
      }
      else {
        if (a[i - 1][j] > 0)
          a[i][j] += a[i - 1][j];
      }
      ans = max (ans, a[i][j]);
    }
  fout << ans;
  return 0;
}