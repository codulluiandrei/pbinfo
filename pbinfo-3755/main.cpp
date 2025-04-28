// Costin Oncescu
#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 100, maxM = maxN;
int N, M, type, a[maxN], b[maxN], x[maxM], y[maxM];
bool isNecessary[maxN];
typedef pair < int, int > atMost2;
atMost2 whereFrom[maxN];
atMost2 merge (atMost2 a, atMost2 b) {
  if (a.first == 0) return b;
  if (b.first == 0) return a;
  if (b.second != 0) return b;
  if (a.second == 0 && b.first != a.first)
    a.second = b.first;
  return a;
}
int main () {
  scanf ("%d\n%d %d", &type, &N, &M);
  for (int i=1; i<=N; i++)
    scanf ("%d", &b[i]), a[i] = b[i];
  for (int i=1; i<=M; i++)
    scanf ("%d %d", &x[i], &y[i]);
  for (int i=M; i>=1; i--)
    if (!(a[x[i]] & a[y[i]]))
      a[x[i]] = a[y[i]] = 0;
  if (type == 1) {
    for (int i=1; i<=N; i++)
      printf ("%d", a[i]);
    printf ("\n");
    return 0;
  }
  for (int i=1; i<=N; i++)
    if (a[i] != 0)
      whereFrom[i].first = i;
  for (int i=1; i<=M; i++)
    whereFrom[x[i]] = whereFrom[y[i]] = merge (whereFrom[x[i]], whereFrom[y[i]]);
  for (int i=1; i<=N; i++) {
    assert (b[i] == 0 || whereFrom[i].first != 0);
    if (b[i] == 1 && whereFrom[i].second == 0)
      isNecessary[whereFrom[i].first] = 1;
  }
  for (int i=1; i<=N; i++)
    printf ("%d", a[i] == 0 || (!isNecessary[i]));
  printf ("\n");
  return 0;
}