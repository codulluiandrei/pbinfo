#include <bits/stdc++.h>
#define md 1000003
#define ll long long
using namespace std;
int N;
ll M;
ll fact;
int main()
{
    cin >> N;
    fact = 1;
    for(int i = 1; i <= N; i++)
    {
        M = M * i % md;
        ll C = 1ll * i * (i - 1) / 2 % md;
        C = C * fact % md;
        M = (M + C) % md;
        fact = 1ll * i * fact % md;
    }
    cout << M << "\n";
    return 0;
}