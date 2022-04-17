#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, i = 1, j = 1, k = 1, mat[22][22]; cin >> n;
    while (i <= n) {
        if (k % 2 == 0 && k % 3 != 0) {
            mat[i][j] = k;
            k++;
            j++;
            if (j == n + 1) {
                j = 1;
                i++;
            }
        } else k++;
    } for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    } return 0;
}