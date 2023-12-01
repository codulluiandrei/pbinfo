#include <bits/stdc++.h>
using namespace std;
 
int a[25], n, t[25];
 
int main()
{
    int i, j;
    long long dif, difmin;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> t[i];
    difmin = (1LL << 61);
    a[n] = 1;
    while (a[0] == 0)
    {
        /// calcul diferente:
        dif = 0;
        for (i = 1; i <= n; i++)
            if (a[i] == 0) dif -= t[i];
            else dif += t[i];
        dif = abs(dif);
        difmin = min(difmin, dif);
 
        for (i = n; a[i] == 1; i--)
            a[i] = 0;
        a[i] = 1;
    }
    cout << difmin;
    return 0;
}