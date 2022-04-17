#include <bits/stdc++.h>
using namespace std;
    int n, mat1[101][101], mat2[101][101], val = 1;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            mat1[i][j] = val, val++;
    }
    for (int i = 1; i <= n / 4; i++)
        for (int j = 1; j <= n / 4; j++)
            mat2[i][j] = mat1[i][j];

    for (int i = n - n / 4 + 1; i <= n; i++)
        for (int j = 1; j <= n / 4; j++)
            mat2[i][j] = mat1[i][j];

    for (int i = 1; i <= n / 4; i++)
        for (int j = n - n / 4 + 1; j <= n; j++)
            mat2[i][j] = mat1[i][j];

    for (int i = n - n / 4 + 1; i <= n; i++)
        for (int j = n - n / 4 + 1; j <= n; j++)
            mat2[i][j] = mat1[i][j];

    for (int i = n / 4 + 1; i <= n - n / 4; i++)
        for (int j = n / 4 + 1; j <= n - n / 4; j++)
            mat2[i][j] = mat1[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (mat2[i][j] != 0) cout << mat2[i][j] << " ";
            else cout << mat1[n - i + 1][n - j + 1] << " ";
        cout << endl;
    } return 0;
}