#include <iostream>
using namespace std;
int a[505][505], n, k, L, H;
int main()
{
    int i, j, k, nrSubmat, s;
    /// citire
    cin >> n >> k >> L >> H;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    /// sume partiale
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    /// numarare submatrice
    nrSubmat = 0;
    for (i = k; i <= n; i++)
        for (j = k; j <= n; j++)
        {
            s = a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k];
            if (L <= s && s <= H)
                nrSubmat++;
        }
    cout << nrSubmat;
    return 0;
}