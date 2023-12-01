#include <iostream>
using namespace std;

int NrDiv(int n)
{
    int i, nr = 0;
    for (i = 1; i * i < n; i++)
        if (n % i == 0) nr += 2;
    if (i * i == n) nr++;
    return nr;
}

int main()
{
    int n, i, x, p, s = 0;
    cin >> n >> p;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        if (NrDiv(x) >= p) s += x;
    }
    cout << s;
    return 0;
}
