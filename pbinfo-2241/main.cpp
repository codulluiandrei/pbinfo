#include <bits/stdc++.h>
using namespace std;

bitset<40000> b;
int n, a[3500];

void Ciur()
{
    int i, j;

    for (i = 4; i <= 32000; i += 2)
        b[i] = 1;
    for (i = 3; i * i <= 32000; i += 2)
        if (b[i] == 0)
            for (j = i * i; j <= 32000; j = j + 2 * i)
                b[j] = 1;
    a[1] = 2;
    n = 1;
    for (i = 3; i <= 32000; i += 2)
        if (b[i] == 0) a[++n] = i;
}

/// calcul Phi(x)
int Phi(int x)
{
    int i, d, phi;
    if (x == 2) return 1;
    d = 2;
    i = 1;
    phi = x;
    while (x > 1 && d * d <= x && i <= n)
    {
        if (x % d == 0)
        {
            while (x % d == 0)
                x /= d;
            phi = phi / d * (d - 1);
        }
        d = a[++i];
    }
    if (x > 1) /// x - prim
        phi = phi / x * (x - 1);
    return phi;
}

int Cmmdc(int x, int y)
{
    int r;
    while (y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

void CitireAfisare()
{
    int i, Q, x, y, d;
    long long sol;
    cin >> Q;
    for (i = 1; i <= Q; ++i)
    {
        cin >> x >> y;
        d = Cmmdc(x, y);
        sol = 1LL * Phi(x) * Phi(y) * d / Phi(d);
        cout << sol << "\n";
    }
}

int main()
{
    Ciur();
    CitireAfisare();
    return 0;
}
