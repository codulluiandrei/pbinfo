#include <iostream>
using namespace std;
int a[102][102], n;
int main()
{
    int i, j, esteMatrixChess;
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    /// bordare
    for (i = 1; i <= n; i++)
    {
        a[0][i] = 1 - a[1][i];
        a[n + 1][i] = 1 - a[n][i];
        a[i][0] = 1 - a[i][1];
        a[i][n + 1] = 1 - a[i][n];
    }
    /// verificare
    esteMatrixChess = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] == a[i-1][j] || a[i][j] == a[i+1][j]
                || a[i][j] == a[i][j-1] || a[i][j] == a[i][j+1])
                    esteMatrixChess = 0;
    if (esteMatrixChess == 1) cout << "DA";
    else cout << "NU";
    return 0;
}