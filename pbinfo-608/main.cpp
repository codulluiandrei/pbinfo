#include <bits/stdc++.h> 
using namespace std;
int n, k, mat[101][101];
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        for (int  j = 1; j <= n; j++)
            if (abs(i - j) <= k || (i + j >= n + 1 - k && i + j <= n + 1 + k  ) ) mat[i][j] = 1;
            else mat[i][j] = 2;
    for (int i = 1; i <= n; i++) {
        for (int  j = 1 ; j <= n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    } return 0;
}