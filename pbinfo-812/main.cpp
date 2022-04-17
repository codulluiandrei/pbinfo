#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, mat[18][18];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || j == 1) {
                if (i == 1) mat[i][j] = j;
                if (j == 1) mat[i][j] = 1;
            } else mat[i][j] = mat[i][j - 1] + mat[i - 1][j];
        }
    } for (int i = n; i > 0; i--) {
        for (int j = 1; j <= n; j++) {
            cout << mat[i][j] << " ";
        } cout << endl;
    } return 0;
}