#include <bits/stdc++.h>
using namespace std;
ifstream in("suma7.in");
ofstream out("suma7.out");
#define cin in
#define cout out
int mat[303][303], slin[303], scol[303];
int diag[616], sdiag1[303], sdiag2[303];
int n, maxim = -1000000, linie = -1, coloana = -1;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
            slin[i] = slin[i] + mat[i][j];
            scol[j] = scol[j] + mat[i][j];
            if (i - j >= 0)
                sdiag1[i - j] = sdiag1[i - j] + mat[i][j];
            else if (i - j < 0) 
                sdiag2[- (i - j)] = sdiag2[- (i - j)] + mat[i][j];
            diag[i + j] = diag[i + j] + mat[i][j];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int temp = slin[i] + scol[j] + diag[i + j] - mat[i][j] * 3;
            if (i - j >= 0)
                temp = temp + sdiag1[i - j];
            else if (i - j < 0) 
                temp = temp + sdiag2[j - i];
            if (temp > maxim) {
                maxim = temp;
                linie = i;
                coloana = j;
            }
        }
    cout << maxim << "\n" << linie << " " << coloana;
    return 0;
}