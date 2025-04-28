#include <bits/stdc++.h>
using namespace std;
int a[305][305], b[305][305], v[305], n;
void Citire()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
}
void SumePartiale()
{
    int i, j;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; j++)
            b[i][j] = a[i][j] + b[i-1][j];
}
int SecSumMax(int v[], int n)
{
    int i, s, smax;
    s = smax = v[1];
    if (s < 0) s = 0;
    for (i = 2; i <= n; ++i)
    {
        s += v[i];
        if (s > smax) smax = s;
        if (s < 0) s = 0;
    }
    return smax;
}
void Solutie()
{
    int i1, i2, j, ssmax, suma;
    ssmax = -200000000;
    for (i1 = 1; i1 <= n; ++i1)
        for (i2 = i1; i2 <= n; ++i2)
        {
            for (j = 1; j <= n; j++)
                v[j] = b[i2][j] - b[i1 - 1][j];
            suma = SecSumMax(v, n);
            ssmax = max(ssmax, suma);
        }
    cout << ssmax;
}
int main()
{
    Citire();
    SumePartiale();
    Solutie();
    return 0;
}