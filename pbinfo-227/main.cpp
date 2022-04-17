#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, mat[18][18]; cin >> n;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            if (i == 0 || i == n + 1 || j == 0 || j == n + 1 || i == 1) {
                mat[i][j] = 0;
                if (i == 1) mat[i][j] = j;
            } else mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j] + mat[i - 1][j + 1];
        }
    } for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (j > n + 1 - i) cout << 0 << " ";
            else cout << mat[i][j] << " ";
        } cout << endl;
    } return 0;
}