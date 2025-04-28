#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, k, P;
    cin >> n;
    m = n;
    /// determina numarul bitilor pe care se reprezinta n
    k = 0;
    if (m == 0) k = 1;
    while (m > 0)
    {
        m /= 2;
        k++;
    }
    /// calculez 2^k - 1
    P = (1 << k) - 1;
    n = n ^ P;
    cout << n;
    return 0;
}