/* Mircea Pasoi, solutie O(N+M) */
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MAX_N 100005
#define FIN "reinvent.in"
#define FOUT "reinvent.out"
int N, M, X, src[MAX_N], dist[MAX_N];
vector<int> G[MAX_N];
queue<int> Q;
int main(void) {
  int i, j, n;
  freopen(FIN, "r", stdin);
  freopen(FOUT, "w", stdout);
  scanf("%d %d %d", &N, &M, &X);
  for (; M; --M) {
    scanf("%d %d", &i, &j);
    G[i].push_back(j);
    G[j].push_back(i);
  }
  memset(src, -1, sizeof(src));
  for (; X; --X) {
    scanf("%d", &n);
    Q.push(n);
    src[n] = n;
  }
  while (!Q.empty()) {
    n = Q.front();
    Q.pop();
    for (vector<int>::iterator it = G[n].begin(); it != G[n].end(); ++it)
      if (src[*it] == -1) {
        Q.push(*it);
        src[*it] = src[n];
        dist[*it] = dist[n]+1;
      } else if (src[*it] != src[n]) {
        printf("%d\n", dist[*it]+dist[n]+1);
        return 0;
      }
  }
  return 0;
} 