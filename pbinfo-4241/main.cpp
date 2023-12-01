#include <bits/stdc++.h>
using namespace std;

int a[100001], sp[100001], n;

int main()
{
    int i, smax, s, sTotal;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    s = sp[0] = a[0];
    if (s < 0) s = 0;
    for (i = 1; i < n; i++)
    {
        s += a[i];
        sp[i] = max(sp[i - 1], s);
        if (s < 0) s = 0;
    }
    s = smax = a[n - 1];
    if (s < 0) s = 0;
    sTotal = smax + sp[n - 2];
    for (i = n - 2; i > 0; i--)
    {
        s += a[i];
        if (smax < s) smax = s;
        if (s < 0) s = 0;
        sTotal = max(sTotal, smax + sp[i - 1]);
    }
    cout << sTotal;
    return 0;
}
