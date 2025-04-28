#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, GMax, i, j;
    int V[1005], G[1005];
    cin >> n >> GMax;
    for(i = 0; i < n; ++i)
        cin >> G[i] >> V[i];
    int rucsac[10005];
    rucsac[0] = 0; // Cu 0kg, obtinem valoarea 0
    for(j = 1; j <= GMax; ++j)
    {
        rucsac[j] = 0;
        for(i = 0; i < n; ++i)
            if(G[i] <= j)
                rucsac[j] = max(rucsac[j], rucsac[j-G[i]] + V[i]);
    }
    cout << rucsac[GMax];
    return 0;
}