#include <iostream>
using namespace std;
int main()
{
    long long n, f, fmax = 0;
    int e, emax = 0;
    cin >> n;
    /// factorul prim 2
    e = 0;
    while (n % 2 == 0)
    {
        e++;
        n /= 2;
    }
    if (e > 0)
    {
        fmax = 2;
        emax = e;
    }
    /// factorii impari:
    for (f = 3; f * f <= n; f += 2)
    {
        e = 0;
        while (n % f == 0)
        {
            e++;
            n /= f;
        }
        if (e >= emax)
        {
            emax = e;
            fmax = f;
        }
    }
    if (n > 1 && emax <= 1) fmax = n;
    cout << fmax;
    return 0;
}