#include <iostream>
using namespace std;
int n, mat[33][33];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        if (i % 2 == 0)
            for (int j = i, k = 1; j > 0; j--, k++)
                cout << mat[j][k] << " ";
        else
            for (int j = i, k = 1; j > 0; j--, k++)
                cout << mat[k][j] << " ";
    for (int j = 2; j <= n; j++)
        if (j % 2 != n % 2)
            for (int i = j, k = n; i <= n; i++, k--)
                cout << mat[k][i] << " ";
        else
            for (int i = j, k = n; i <= n; i++, k--)
                cout << mat[i][k] << " ";
    return 0;
}