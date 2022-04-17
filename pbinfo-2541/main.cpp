#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, mat[25][25];
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <=n; j++)
            if (i == 1 || i == n || j == 1 || j == n) mat[i][j] = i + j;
    for (int j = n - 1; j >= 2; j--)
        for (int i = n - 1; i >= 2; i--)
            mat[i][j] = mat[i - 1][j + 1] + mat[i][j + 1] + mat[i + 1][j + 1];
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <=n ; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    } return 0;

}