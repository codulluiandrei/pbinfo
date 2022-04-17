#include <iostream>
using namespace std;
int main() {
    int mat[101][101], n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m - 1; j++)
            swap(mat[i][j], mat[i][j + 1]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    } return 0;
}