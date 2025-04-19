#include <bits/stdc++.h>
using namespace std;
int nrDiv(int n)
{
    int nr = 1, d=2, k;
    while(n>1)
    {
        k = 0;
        while (n % d == 0)
        {
            n = n / d;
            k++;
        }
        if(k)
            nr = nr * (k + 1);
        d++;
        if(n>1 && d*d>n)
            d=n;
    }
    return nr;
}
int triunghiular(int n)
{
    int p=1, q=1, k=0, i=2;
    if (n == 1)
        return 3;
    while (k <= n)
    {
        if (i % 2 == 0)
            p = nrDiv(i + 1);
        else
            q = nrDiv((i + 1) / 2);
        k = p * q;
        i++;
    }
    return i * (i - 1) / 2;
}
int main()
{
    int n;
    cin >> n;
    cout << triunghiular(n);
    return 0;
}