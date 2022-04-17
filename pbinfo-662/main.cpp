#include <iostream>
using namespace std;
int main() {
    int n, m, mat[105][105], maxim = 0, temp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++) {
        int S = 0;
        for (int j = 1; j <= m; j++)
            if (mat[i][j] % 2 == 0)
                S = S + mat[i][j];
        if (S > maxim) {
            maxim = S;
            temp = i;
        }
    } cout << temp;
    return 0;
}