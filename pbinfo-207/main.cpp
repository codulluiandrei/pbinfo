#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, mat[101][101];
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            mat[i][j] = n - j + 1;

    for(int i = 1; i <= n; i++) mat[i][i] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    } return 0;
}