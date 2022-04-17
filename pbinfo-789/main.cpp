#include <iostream>
using namespace std;
int n, m, k = 0, mat[101][101], v[10001], f[10001], maxim = -1;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int pozitie = 0;
            for (int l = 1; l <= k && pozitie == 0; l++)
                if (v[l] == mat[i][j]) pozitie = l;
            if (pozitie == 0) {
                k++; 
                v[k] = mat[i][j];
                f[k] = 1;
            } else f[pozitie]++;
        }
    for (int i = 1; i <= k; i++)
        if (f[i] > 1)
            if (v[i] > maxim) maxim = v[i];
    if (maxim == -1) cout << "IMPOSIBIL";
    else cout << maxim;
    return 0;
}