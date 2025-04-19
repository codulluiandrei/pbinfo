#include <bits/stdc++.h>
using namespace std;
int n, m, mat[1001][1001], rez = 0;
int diagx[] = { 1, 1, -1, -1 }, diagy[5] = { 1, -1, 1, -1 };
int main() {
    cin >> n >> m;
    while (m--) {
        int i, j, p;
        cin >> i >> j >> p;
        mat[i][j] = 1;
        for (int x = 1; x <= p; x++) {
            for (int k = 0; k < 4; k++)
                if (i + x * diagx[k] > 0 && i + x * diagx[k] <= n && j + x * diagy[k] > 0 && j + x * diagy[k] <= n)
                    mat[i + x * diagx[k]][j + x * diagy[k]] = 1;
        }
    } for (int j = 1; j <= n; j++)
        for(int i = 1; i <= n; i ++)
            if (mat[i][j] == 0) rez++;
    cout << rez;
    return 0;
}