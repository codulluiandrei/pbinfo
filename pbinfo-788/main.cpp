#include <iostream>
using namespace std;
int mat[101][101], n, m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++) {
        bool adv = true;
        if (mat[i][1] < 2) adv = false;
        if (mat[i][1] > 2 && mat[i][1] % 2 == 0) adv = false;
        for (int d = 3 ; d * d <= mat[i][1] && adv; d = d + 2)
            if (mat[i][1] % d == 0) adv = false;
        if (adv == true) {
            for (int j = 1, k = m; j < k; j++, k--) {
                int temp = mat[i][j];
                mat[i][j] = mat[i][k];
                mat[i][k] = temp;
            }
        }
    } for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    } return 0;
}