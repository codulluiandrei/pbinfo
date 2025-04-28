#include <bits/stdc++.h>
#define nmax 100003
using namespace std;
int n, d[nmax], k;
/// d[i]=capatul celui de-al i-lea subsir
void CautBin(int x)
{
    if (x <= d[k])
    {
        d[++k] = x;
        return ;
    }
    int st, dr, p, mid;
    p = st = 1; dr = k;
    while (st <= dr)
    {
        mid = (st + dr) / 2;
        if (d[mid] < x)
        {
            p = mid;
            dr = mid - 1;
        }
        else st = mid + 1;
    }
    d[p] = x;
}
int main()
{
    int i, x;
    cin >> n >> x;
    k = 1;
    d[1] = x;
    for (i = 2; i <= n; i++)
    {
        cin >> x;
        CautBin(x);
    }
    cout << k << "\n";
    return 0;
}