/*
    Complexitate O(n) - 70 puncte
*/
#include <bits/stdc++.h>
#define MOD 123457
using namespace std;
int n, par[100003], impar[100003];
int main()
{
    int i;
    cin >> n;
    if (n == 1)
    {
        cout << "10\n";
        return 0;
    }
    par[1] = 4; impar[1] = 5;
    for (i = 2; i <= n; i++)
    {
        par[i] = (5 * par[i-1] + 5 * impar[i - 1]) % MOD;
        impar[i] = 5 * impar[i - 1] % MOD;
    }
    cout << (par[n] + impar[n]) % MOD << "\n";
    return 0;
}