#include <bits/stdc++.h>
#define nmax 100001
#define mod 30103
using namespace std;
int par[nmax], impar[nmax], n;
int main()
{
    cin >> n;
    par[1] = 4;
    impar[1] = 5;
    for (int i = 2; i <= n; i++)
    {
        par[i] = 4 * impar[i - 1] % mod;
        impar[i] = 5 * par[i - 1] % mod;
    }
    cout << (par[n] + impar[n]) % mod;
    return 0;
}