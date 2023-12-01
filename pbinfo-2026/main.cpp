/// Solutie - Moca Andrei - 100p
#include <iostream>
#include <algorithm>
using namespace std;
int a[10002][102], n, x, c = 1, y, s, smax, k, l[10002], nr, cerinta;
bool cmp(int a1, int a2)
{
    if (a1 > a2)
        return 1;
    return 0;
}
int main()
{
    cin >> k >> n >> x;
    int imin = x, imax = x;
    for (int i = 2; i <= n; i++)
    {
        cin >> y;
        imin = min(imin, y);
        imax = max(imax, y);
        if (x == y)
            c++;
        if (x != y || i == n)
        {
            l[x]++;
            a[x][l[x]] = c;
            sort (a[x] + 1, a[x] + l[x] + 1, cmp);
            if (l[x] > k)
                a[x][l[x]] = 0, l[x] = k;
            c = 1;
        }
        x = y;
    }
    cin >> cerinta;
    for (int i = imin; i <= imax; i++)
    {
        for (int j = 1; j <= k; j++)
            s += a[i][j];
        if (s > smax)
            smax = s, nr = i;
        else
            if (s == smax)
                nr = i;
        s = 0;
    }
    if (cerinta == 1)
        cout << smax;
    else
        if (cerinta == 2)
            cout << nr;
    return 0;
}
