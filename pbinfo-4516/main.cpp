#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long c, n, nrMax = 0;
    cin >> n;
    while (n >= 100)
    {
        c = n % 1000;
        if (c > nrMax) nrMax = c;
        n /= 10;
    }
    cout << nrMax;
    return 0;
}