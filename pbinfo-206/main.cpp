#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n, mat[22][22];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mat[i][j] = min(i, j);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << mat[i][j] << " ";
        cout << endl;
    } return 0;
}