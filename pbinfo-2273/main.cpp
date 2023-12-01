/**
   Complexitate O(n x n)
*/
#include <bits/stdc++.h>
#define nmax 200005
#define oo 2000000001
using namespace std;

int a[nmax], n;

inline int Min(int x, int y, int z)
{
    return min(min(x, y), z);
}

inline int Max(int x, int y, int z)
{
    return max(max(x, y), z);
}

int main()
{
    int i, j, difmin, P, Q, X, Y, Z, d;
    /// citire
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];

    /// sume partiale
    for (i = 2; i <= n; i++)
        a[i] += a[i - 1];

    /// pentru fiecare i=1..n-2 caut liniar pozitia lui j
    P = 1; Q = 2;
    X = a[1]; Y = a[2] - a[1]; Z = a[n] - a[2];
    difmin = Max(X, Y, Z) - Min(X, Y, Z);
    for (i = 1; i <= n - 2; i++)
        for (j = i + 1; j < n; j++)
        {
            X = a[i];
            Y = a[j] - a[i];
            Z = a[n] - a[j];
            d = Max(X, Y, Z) - Min(X, Y, Z);
            if (d < difmin)
            {
                difmin = d;
                P = i; Q= j;
            }
        }

    /// afisare
    cout << P << " " << Q << "\n";

    return 0;
}
