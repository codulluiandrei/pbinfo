#include <bits/stdc++.h>
using namespace std;
int n, mat[101][101], temp;
void functie(int i, int j, int temp) {
    i = 3 * (i - 1) + 1;
    j = 3 * (j - 1) + 1;
    mat[i][j] = temp;
    mat[i + 2][j] = temp;
    mat[i][j + 2] = temp;
    mat[i + 1][j + 1] = temp;
    mat[i + 2][j + 2] = temp;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            temp++, functie(i, j, temp);
    for (int i = 1; i <= 3 * n; i++) {
        for (int j = 1; j <= 3 * n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    } return 0;
}