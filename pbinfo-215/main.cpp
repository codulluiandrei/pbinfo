#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, poz = 0, mat[100][100]; cin >> n;
    while (n) {
        mat[6][++poz] = n % 10;
        n = n / 10;
    } for (int i = poz; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            mat[i][j] = mat[i + 1][j];
        } for (int j = i + 1; j <= 6; j++) {
            mat[i][j] = mat[i + 1][i];
        }
    } for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    } return 0;
}