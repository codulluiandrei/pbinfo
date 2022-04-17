#include <iostream>
using namespace std;
int main() {
    int mat[101][101], n, m, x;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            cin >> mat[i][j];
    x = mat[n - 1][m - 1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                mat[i][j] = x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
                cout << mat[i][j] << " ";
        cout << endl;
    } return 0;
}