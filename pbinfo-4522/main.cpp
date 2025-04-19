#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ePrim, j, i, n, y, x, valPrim = 2000000000;
    cin >> n >> x;
    for (j = 1; j <= n; j++)
    {
        cin >> y;
        // verifica daca y este prim
        ePrim = 1;
        for (i = 2; i * i <= y; i++)
            if (y % i == 0) ePrim = 0;
        if (ePrim == 1)
        {
            if (abs(valPrim - x) > abs(y - x))
                valPrim = y;
            else if (abs(valPrim - x) == abs(y - x) && valPrim > y)
                valPrim = y;
        }
    }
    cout << valPrim;
    return 0;
}