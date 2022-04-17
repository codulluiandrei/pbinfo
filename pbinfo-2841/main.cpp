#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, mat[25][25];
    cin >> n >> m;
    int temp1 = 2, temp2 = 1, i = 1, j = 1;
    while (temp2 <= n * m) {
        mat[i][j] = temp1;
        j++;
        if (m + 1 == j) {
            j = 1;
            i++;
        } if ((temp1 + 2) % 5 == 0) temp1 = temp1 + 4;
          else temp1 = temp1 + 2;
          temp2++;
    } for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    } return 0;
}