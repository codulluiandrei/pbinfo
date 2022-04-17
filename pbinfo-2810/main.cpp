#include <iostream>
using namespace std;
int main() {
    int n, m;
    double mat[101][101];
    cin >> n;
    m = n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = n; i >= n / 2; i--)
        for (int j = 1; j <= m; j++)
            mat[i + 1][j] = mat[i][j];
    n++;
    for (int j = 1; j <= n; j++)
        mat[n / 2 + 1][j] = 0;
    for (int j = 1; j <= m; j++) {
        double S = 0;
        for (int i = 1; i<= n; i++)
            S = S + mat[i][j];
        mat[n / 2 + 1][j] = S / (n - 1);
    } for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    } return 0;
}