#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, mat[51][51];
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
        for (int j = i; j <=n - i + 1; j++)
            mat[i][j] = mat[n - i + 1][j] = mat[j][i] = mat[j][n - i + 1] = i;
    if (n % 2 == 1) mat[n / 2 + 1][n / 2 + 1] = n / 2 + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    } return 0;
}