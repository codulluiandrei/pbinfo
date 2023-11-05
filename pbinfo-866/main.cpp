#include <bits/stdc++.h>
using namespace std;
ifstream in("acces.in");
ofstream out("acces.out");
#define cin in
#define cout out
int n, m, mat[1010][1010], minim = 10000001;
int ql[1000001], qc[1000001];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int main() {
      cin >> n >> m;
      for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                  char temp;
                  cin >> temp;
                  if (temp == '-') mat[i][j] = 0;
                  else if (temp == '#') mat[i][j] = -1;
                  else mat[i][j] = 1, ql[1] = i, qc[1] = j;
            }
      int contor = 1, prima = 1;
      while (contor <= prima) {
            int i = ql[contor], j = qc[contor];
            for (int v = 0; v < 4; v++) {
                  int ii = i + dx[v], jj = j + dy[v];
                  if (ii > 0 && jj > 0 && jj <= m && ii <= n && mat[ii][jj] == 0)
                        prima++, ql[prima] = ii, qc[prima] = jj, mat[ii][jj] = mat[i][j] + 1;
            }
            contor++;
      } for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                  if (mat[i][j] != -1)
                        cout << mat[i][j] - 1 << " ";
                  else
                        cout << mat[i][j] << " ";
            cout << endl;
      }
      return 0;
}