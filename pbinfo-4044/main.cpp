// Soluție Bogdan Vlad-Mihai, clasa a XII-a, Liceul Teoretic "Aurel Vlaicu" Orăștie
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m; cin >> n >> m;
  vector<string> mat(n);
  for (auto &line : mat)
    cin >> line;
  vector<vector<int>> val(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mat[i][j] == 'A')
        val[i][j] = 1;
      else if (mat[i][j] == 'N')
        val[i][j] = -1;
  int result = 0;
  vector<int> fr(2 * (n * m + 1));
  fr[n * m]++;
  for (int low = 0; low < n; low++) {
    vector<int> v(m);
    for (int up = low; up < n; up++) {
      for (int i = 0; i < m; i++)
        v[i] += val[up][i];
      int prefixSum = 0;
      for (int x : v) {
        prefixSum += x;
        result += fr[n * m + prefixSum];
        fr[n * m + prefixSum]++;
      }
      prefixSum = 0;
      for (int x : v) {
        prefixSum += x;
        fr[n * m + prefixSum]--;
      }
    }
  }
  cout << result << "\n";
  return 0;
}