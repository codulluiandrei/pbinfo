#include <iostream>
#include <cmath>
using namespace std;

int cmmdc(int a, int b);

int main()
{
    int n, x, y, z, d;
    bool ok = true;
    bool ok2 = false;
    cin >> n;
    if (n < 2)
    {
        cout << "DA";
        return 0;
    }
    if (n == 2)
    {
        cin >> x >> y;
        if ( abs(x - y) != 1 )
            cout << "DA";
        else
            cout << "NU";
        return 0;
    }
    cin >> x >> y >> z;
    if (x != y || y != z)
        ok2 = true;
    d = cmmdc( abs(x - y), abs(y - z) );
    if (d == 1)
        ok = false;
    for (int i = 4; i <= n && ok; i++)
    {
        y = z;
        cin >> z;
        if (y != z)
            ok2 = true;
        d = cmmdc(d, abs(y - z) );
        if (d == 1)
            ok = false;
    }
    if (ok && ok2)
        cout << "DA";
    else
        cout << "NU";
}

int cmmdc(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    int r;
    while ( b )
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}