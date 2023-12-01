// solutie Meet in the Middle

#include <bits/stdc++.h>
#define nmax 1050000
using namespace std;

int a[23], b[23], n, na, nb, s, M;
int x[nmax], y[nmax], nx, ny;

void Citire()
{
    int i;
    cin >> n >> s;
    na = n / 2;
    for (i = 1; i <= na; i++)
        cin >> a[i];
    nb = 0;
    for (i = na + 1; i <= n; i++)
    {
        nb++;
        cin >> b[nb];
    }
}

void Subsets(int a[], int n, int x[], int &nx)
{
    int i, suma;
    int t[23] = {0};
    nx = 0;
    while (t[0] == 0)
    {
        suma = 0;
        for (i = 1; i <= n; i++)
            if (t[i] == 1) suma += a[i];
        x[++nx] = suma;

        for (i = n; t[i] == 1; i--)
            t[i] = 0;
        t[i] = 1;
    }
}

void Rezolvare()
{
    int i, j;
    M = 0;
    sort(x + 1, x + nx + 1);
    sort(y + 1, y + ny + 1);
    for (i = 1; i <= nx && x[i] <= s; i++)
        if (M < x[i]) M = x[i];
    for (i = 1; i <= ny && y[i] <= s; i++)
        if (M < y[i]) M = y[i];
    j = ny;
    for (i = 1; i <= nx; i++)
    {
        while (j >= 1 && x[i] + y[j] > s)
            j--;
        if (j >= 1) M = max(M, x[i] + y[j]);
    }
    cout << M;
}

int main()
{
    Citire();
    Subsets(a, na, x, nx);
    Subsets(b, nb, y, ny);
    Rezolvare();
    return 0;
}
