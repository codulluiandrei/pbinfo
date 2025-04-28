#include <bits/stdc++.h>
#define INF 2000000000
#define MAXN 7001
#define ABS(x) ((x) < 0 ? (-(x)) : (x))
using namespace std;
ifstream fin ("palind.in");
ofstream fout ("palind.out");
int N, x, A[2][MAXN], cnt[MAXN];
int sol[2][2];
void Go (int t) {
  int i, nr, val, mmin = INF;
  memset (cnt, 0, sizeof(cnt));
  for (val = nr = 0, i = 1; i < MAXN; i ++)
    val += nr, val += A[t][i - 1], nr += A[t][i - 1], cnt[i] += val;
  for (nr = val = 0, i = MAXN - 2; i >= 1; i --)
    val += nr, val += A[t][i + 1], nr += A[t][i + 1], cnt[i] += val;
  for (nr = 0, i = 1; i < MAXN; i ++) {
    if (cnt[i] == mmin)
      nr ++;
    if (cnt[i] < mmin)
      mmin = cnt[i], nr = 1;
  }
  sol[t][0] = mmin, sol[t][1] = nr;
}
void Solve () {
  memset (A, 0, sizeof(A));
  fin >> N;
  for(int i = 1; i <= N; i ++)
    fin >> x, A[i & 1][x] ++;
  Go (0), Go (1);
  fout << sol[0][0] + sol[1][0] << ' ' << sol[0][1] * sol[1][1] << '\n';
}
int main () {
  int T;
  fin >> T;
  while (T --)
    Solve();
  fin.close();
  fout.close();
  return 0;
}