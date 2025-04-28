#include <bits/stdc++.h>
#define P 777013
using namespace std;
int main()
{
    int n, x, y, z, i;
    cin >> n;
    x = 26;
    y = 26 * 26;
    if (n == 1)
    {
        cout << x << "\n";
        return 0;
    }
    if (n == 2)
    {
        cout << y << "\n";
        return 0;
    }
    for (i = 3; i <= n; i++)
    {
        z = 25 * (x + y) % P;
        x = y;
        y = z;
    }
    cout << z << "\n";
    return 0;
}