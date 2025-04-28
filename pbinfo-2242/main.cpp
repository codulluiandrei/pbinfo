#include <iostream>
#define nmax 100002
using namespace std;
int a[nmax], lis[nmax], n, k;
// lis[i]=capatul minim al unui subsir de lungime i
void Citire()
{
    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
}
// caut in lis[1..k] cea mai din stanga pozitie m cu x <= lis[m]
int CautBin(int x)
{
    int st, dr, sol, m;
    st = 1; dr = k;
    sol = k;
    while (st <= dr)
    {
        m = (st + dr) / 2;
        if (x <= lis[m])
        {
            sol = m;
            dr = m - 1;
        }
        else st = m + 1;
    }
    return sol;
}
int LIS()
{
    int i, x, p;
    lis[1] = a[1];
    k = 1;
    for (i = 2; i <= n; ++i)
    {
        x = a[i];
        if (x > lis[k]) lis[++k] = x;
        else if (x <= lis[1]) lis[1] = x;
        else
        {
            // caut in lis[1..k] cea mai din stanga pozitie p cu x <= lis[p]
            p = CautBin(x);
            lis[p] = x;
        }
    }
    return k;
}
void Afisare()
{
    int L;
    L = LIS();
    L = n - L;
    cout << L << "\n";
}
int main()
{
    Citire();
    Afisare();
    return 0;
}