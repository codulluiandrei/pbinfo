// Soluție Bogdan Vlad-Mihai, clasa a XII-a, Liceul Teoretic "Aurel Vlaicu" Orăștie
#include <bits/stdc++.h>
using namespace std;
const int LIMIT = 100 * 1000;
const int INF = 1000 * 1000 * 1000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n; cin >> n;
  queue<int> q;
  vector<int> minTime(LIMIT + 1, INF);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    q.push(x);
    minTime[x] = 0;
  }
  while ((int)q.size() > 0) {
    int val = q.front();
    q.pop();
    for (int d = 1; d * d <= val; d += 1 + val % 2)
      if (val % d == 0)
        for (int add : {d, val / d})
          if (add + val <= LIMIT && minTime[add + val] > minTime[val] + 1) {
            minTime[val + add] = minTime[val] + 1;
            q.push(val + add);
          }
  }
  int m; cin >> m;
  for (int mm = 0; mm < m; mm++) {
    int x; cin >> x;
    if (minTime[x] == INF)
      cout << "-1\n";
    else
      cout << minTime[x] << "\n";
  }
  return 0;
}