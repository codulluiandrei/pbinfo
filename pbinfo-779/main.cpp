#include <iostream>
using namespace std;
int n, m, mat[102][102];
int diagx[] = {0, 0, -1, 1}, diagy[] = {1, -1, 0, 0};
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mat[i][j];
    int contor = 0;
    for (int i = 1; i <= n; i++)
        mat[i][0] = mat[i][m + 1] = 0;
    for (int j = 1; j <= m; j++)
        mat[0][j] = mat[n + 1][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            bool adv = true;
            for (int k = 0 ; k < 4 ; k ++)
                if (mat[i + diagx[k]][j + diagy[k]] % 2 != 0)
                    adv = false;
            if (adv) contor++;
        } cout << contor;
    return 0;
}