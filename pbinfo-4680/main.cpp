#include <iostream>
using namespace std;
int a[105][105], n, m, c;
/// returneaza 1 daca submatricea c x c cu centrul in (x,y) e centrata
int EsteCentrata(int x, int y)
{
    int i, j;
    for (i = x - c; i <= x + c; i++)
        for (j = y - c; j <= y + c; j++)
            if (a[x][y] < a[i][j]) return 0;
    return 1;
}
int main()
{
    int i, j, nrCentrate;
    /// citire
    cin >> n >> m >> c;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            cin >> a[i][j];
    /// numarare submatrice
    nrCentrate = 0;
    for (i = c + 1; i <= n - c; i++)
        for (j = c + 1; j <= m - c; j++)
            nrCentrate += EsteCentrata(i, j);
    cout << nrCentrate;
    return 0;
}