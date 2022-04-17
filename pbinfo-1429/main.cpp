#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, mat[35][35], i, j;
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i + j <= n + 1) mat[i][j] = i + j - 1;
            else mat[i][j] = 2 * n - i - j + 1;
        }
    } for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            cout << mat[i][j] <<" ";
        cout << endl;
    } return 0;
}