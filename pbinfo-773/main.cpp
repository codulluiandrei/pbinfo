#include <iostream>
using namespace std;
int main() {
    int n, m, mat[101][101], v[10001], f[10001], k;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    k = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int poz = 0;
            for (int p = 1; p <= k && poz == 0; p++)
                if (v[p] == mat[i][j]) poz = p;
            if (poz == 0) {
                k++;
                v[k] = mat[i][j];
                f[k] = 1;
            } else f[poz] ++;
        } int maxim = f[1], pozmax  = 1;
    for(int i = 2; i <= k; i++)
        if (f[i] > maxim) {
            maxim = f[i];
            pozmax = i;
        } else if (f[i] == maxim)
                if (v[i] > v[pozmax])
                    pozmax = i;
    cout << v[pozmax];
    return 0;
}