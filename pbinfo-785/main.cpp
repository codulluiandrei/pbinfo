#include <iostream>
using namespace std;
int mat[101][101], n, m, lmax = 1, cmax = 1, lmin = 1, cmin = 1;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (mat[i][j] > mat[lmax][cmax]) {
                lmax = i; cmax = j;
            } if (mat[i][j] < mat[lmin][cmin]) {
                lmin = i;
                cmin = j;
            }
        }
    if (lmin > lmax) {
        int temp = lmin;
        lmin = lmax;
        lmax = temp;
    }
    if (cmin > cmax) {
        int temp = cmin;
        cmin = cmax;
        cmax = temp;
    } for (int i = lmax; i < n; i++)
        for (int j = 1; j <= m; j++)
            mat[i][j] = mat[i + 1][j];
    n--;
    if (lmin != lmax) {
        for (int i = lmin; i < n; i++)
            for (int j = 1; j <= m; j++)
                mat[i][j] = mat[i + 1][j];
        n--;
    } for (int i = 1; i <= n; i++)
        for (int j = cmax; j < m; j++)
            mat[i][j] = mat[i][j + 1];
    m--;
    if (cmin != cmax) {
        for (int i = 1; i <= n; i++)
            for (int j = cmin; j < m; j++)
                mat[i][j] = mat[i][j + 1];
    m--;
    } for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    } return 0;
}