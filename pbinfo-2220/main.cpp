/// Complexitate O(n)
#include <bits/stdc++.h>
#define nmax 100002
using namespace std;

int a[nmax], s[nmax], d[nmax], n;

int main()
{
    int i, M;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];

    /// calcul maxime partiale de la stanga la dreapta:
    /// s[i] = max(a[1], a[2], ..., a[i])
    s[1] = a[1];
    for (i = 2; i <= n; i++)
        s[i] = max(s[i - 1], a[i]);

    /// calcul minime partiale de la dreapta la stanga:
    /// d[i] = min(a[i], a[i+1], ..., a[n])
    d[n] = a[n];
    for (i = n - 1; i >= 1; i--)
        d[i] = min(d[i + 1], a[i]);

    /// Pentru pozitia i, diferenta maxima este data de diferenta dintre
    /// cea mai mare valoare din a[1..i], adica s[i], si cea mai mica
    /// valoare din a[i+1..n], adica d[i+1].
    M = s[1] - d[2];
    for (i = 2; i < n; i++)
        M = max(M, s[i] - d[i + 1]);

    cout << M;
    return 0;
}
