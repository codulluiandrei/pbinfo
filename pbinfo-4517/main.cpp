#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ePrim, j, n, cnt = 0;
    long long x, i;
    cin >> n;
    for (j = 1; j <= n; j++)
    {
        cin >> x;
        i = sqrt(x);
        if (i * i == x)
        {
            x = i;
            /// verific daca x e prim
            ePrim = 1;
            if (x < 2) ePrim = 0;
            else if (x == 2) ePrim = 1;
            else if (x % 2 == 0) ePrim = 0;
            else
            {
                for (i = 3; i * i <= x; i += 2)
                    if (x % i == 0) ePrim = 0;
            }
            if (ePrim == 1) cnt++;
        }
    }
    cout << cnt;
    return 0;
}