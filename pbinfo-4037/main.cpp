#include <iostream>
using namespace std;

int main()
{
    int a[1002], n, x, k, i, p;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    cin >> x >> k;

    /// cea mai din stanga pozitie p a lui x
    for (p = 1; p <= n && a[p] != x; p++)
        ;
    if (p > n)
    {
        cout << "0\n0\n0\n";
        return 0;
    }
    cout << p << "\n";

    /// cea mai din dreapta pozitie p a lui x
    for (p = n; p >= 1 && a[p] != x; p--)
        ;
    cout << p << "\n";

    /// a k-a aparitie a lui x in a:
    for (i = 1; i <= n; i++)
        if (a[i] == x)
        {
            k--;
            if (k == 0)
            {
                cout << i << "\n";
                return 0;
            }
        }
    cout << "0\n";
    return 0;
}
