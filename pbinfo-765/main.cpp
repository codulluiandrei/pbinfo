#include <iostream>
using namespace std;
int n, m, q;
long long int mat[1001][1001], S[1005][1005];
long long int maxim = -1;
int main() {
      cin >> n >> m >> q;
      for (int i = 0; i <= n; i++)
            S[i][0] = 0;
      for (int j = 0; j <= m; j++)
            S[0][j] = 0;
      for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                  cin >> mat[i][j];
      for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++)
                  S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + mat[i][j];
      for (int v = 1; v <= q; v++) {
            int is, js, ii, jj;
            cin >> is >> js >> ii >> jj;
            long long suma = S[ii][jj] - S[is - 1][jj] - S[ii][js - 1] + S[is - 1][js - 1];
            if (suma > maxim)
                  maxim = suma;
      }
      cout << maxim;
      return 0;
}