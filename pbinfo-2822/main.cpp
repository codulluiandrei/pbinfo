#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, mat[30][30];
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
        mat[1][i] = i;
    for (int i = 1 ; i <= n ; i++)
        mat[i][n] = n;
    for (int i = 2 ; i <= n ; i++) {
        for (int j = 1 ; j < n ; j++)
            mat[i][j] = mat[i - 1][j] + mat[i - 1][j + 1];
    } for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << mat[j][i] << " ";
        cout << endl;
    } return 0;
}