// Reverse order PQ Andrei Constantinescu
#include <bits/stdc++.h>
using namespace std;
using Test = vector<vector<int>>;
int SolveReverseOrderPq(const Test& T) {
  const int N = T.size();
  vector<vector<bool>> vis(N);
  for (int i = 0; i < N; ++i) {
    vis[i].resize(i + 1, false);
  }
  priority_queue<tuple<int, int, int>> pq;
  pq.emplace(T[0][0], 0, 0);
  int largest = numeric_limits<int>::max();
  for (int t = N * (N + 1) / 2; t > 0; --t) {
    // Get queue's top.
    int d, i, j;
    tie(d, i, j) = pq.top();
    pq.pop();
    // Update answer.
    largest = min(largest, d - t);
    // Progress.
    vis[i][j] = true;
    if (i + 1 < N and (j == i or vis[i][j + 1])) {
      pq.emplace(T[i + 1][j + 1], i + 1, j + 1);
    }
    if (i + 1 < N and (j == 0 or vis[i][j - 1])) {
      pq.emplace(T[i + 1][j], i + 1, j);
    }
  }
  return largest;
}
int main() {
  ifstream cin("detonator.in");
  ofstream cout("detonator.out");
  int Q = 0;
  cin >> Q;
  while (Q--) {
    int N = 0;
    cin >> N;
    Test T(N);
    for (int i = 0; i < N; ++i) {
      T[i].resize(i + 1);
      for (int j = 0; j <= i; ++j) {
        cin >> T[i][j];
      }
    }
    cout << SolveReverseOrderPq(T) << '\n';
  }
}