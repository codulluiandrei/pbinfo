#include <iostream>
using namespace std;
int main() {
    int mat[101][101], v[101], n, m, maxim = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mat[i][j] % 2 == 0)
                v[i]++;
    for (int i = 1; i <= n; i++)
        if (v[i] > maxim) maxim = v[i];
    for (int i = 1; i <= n; i++)
        if (v[i] == maxim) cout << i << " ";
    return 0;
}