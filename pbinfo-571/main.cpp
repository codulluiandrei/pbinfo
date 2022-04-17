#include <bits/stdc++.h>
using namespace std;
int mat[1001][1001], n, m, k, i, j, temp1, temp2, temp3 = 2;
int main() {
    cin >> n >> m >> k;
    for (i = 1; i <= n; i += k) {
        if (temp3 == 1) temp3 = 2;
        else temp3 = 1;
        if (temp3 == 1)
            for (j = k + 1; j <= m; j += k * 2)
                for (temp1 = i; temp1 <= i + k - 1; temp1++)
                    for (temp2 = j; temp2 <= j + k - 1; temp2++)
                        mat[temp1][temp2] = 1;
        else
            for (j = 1; j <= m; j += k * 2)
                for (temp1 = i; temp1 <= i + k - 1; temp1++)
                    for (temp2 = j; temp2 <= j + k - 1; temp2++)
                        mat[temp1][temp2] = 1;
    } for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++)
            cout << mat[i][j];
        cout << endl;
    } return 0;
}