#include <bits/stdc++.h>
#define nmax 100001
using namespace std;

int n, a[nmax], rmin[18][nmax], rmax[18][nmax];
int P[nmax]; /// P[i] = j : secventa de la j la i are doar
             ///            numere distincte
int fr[nmax], lg[nmax];

void Citire()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void ConstructieP()
{
    int i, j, x;
    j = 1;
    for (i = 1; i <= n; i++)
    {
        x = a[i];
        while (fr[x] != 0)
        {
            fr[a[j]]--;
            j++;
        }
        fr[x]++;
        P[i] = j;
    }
}

void RMQ()
{
    int i, j, k;
    /// lg[i] = k - exponentul maxim cu proprietatea
    /// ca 2^k este mai mic sau egal cu i
    lg[1] = 0;
    for (i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;

    /// ---------------- rmin ------------------------
    for (i = 1; i <= n; i++)
        rmin[0][i] = a[i];

    for (i = 1; (1 << i) <= n; i++)
        for (j = (1 << i); j <= n; j++)
        {
            k = 1 << (i - 1);
            rmin[i][j] = min(rmin[i - 1][j], rmin[i - 1][j - k]);
        }

    /// ---------------- rmax ------------------------
    for (i = 1; i <= n; i++)
        rmax[0][i] = a[i];

    for (i = 1; (1 << i) <= n; i++)
        for (j = (1 << i); j <= n; j++)
        {
            k = 1 << (i - 1);
            rmax[i][j] = max(rmax[i - 1][j], rmax[i - 1][j - k]);
        }
}

void Interogari()
{
    int Q, x, y, k, m, M;
    cin >> Q;
    while (Q--)
    {
        cin >> x >> y;
        if (P[y] <= x) /// secventa a[x..y] are doar nr. distincte
        {
            k=lg[y - x + 1];
            m = min(rmin[k][x + (1<<k) - 1], rmin[k][y]);
            M = max(rmax[k][x + (1<<k) - 1], rmax[k][y]);
            if (M - m == y - x) cout << "1";
            else cout << "0";
        }
        else cout << "0";
    }
}

int main()
{
    Citire();
    ConstructieP();
    RMQ();
    Interogari();
    return 0;
}
