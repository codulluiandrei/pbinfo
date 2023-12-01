#include <bits/stdc++.h>
#define nmax 101
using namespace std;

int a[nmax][nmax], n;

void Citire()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
}

int VerifMatAd()
{
    int i, j;
    /// verifica daca pe diagonala principala este doar 0
    for (i = 1; i <= n; i++)
        if (a[i][i] != 0) return 0;

    /// verifica simetria si daca a[i][j]=0..1
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++)
        {
            if (a[i][j] < 0 || a[i][j] > 1) return 0;
            if (a[i][j] != a[j][i]) return 0;
        }
    return 1;
}

int main()
{
    Citire();
    cout << VerifMatAd() << "\n";
    return 0;
}
