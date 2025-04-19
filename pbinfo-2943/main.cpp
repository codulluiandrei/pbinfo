#include <bits/stdc++.h>
#define nmax 403
using namespace std;
int a[nmax][nmax], v[nmax], n, T;
void Citire()
{
    int i, j, A, B, C, D;
    cin >> T >> n >> A >> B >> C >> D;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = a[i - 1][j] + (A * i + B * j + C) % D;
}
void Rezolvare()
{
    int L1, L2, i, j, s;
    long long answer = 0;
    for (L1 = 1; L1 <= n; L1++)
        for (L2 = L1; L2 <= n; L2++)
        {
            for (i = 1; i <= n; i++)
                v[i] = a[L2][i] - a[L1 - 1][i];
            s = 0;
            j = 1;
            for (i = 1; i <= n; i++)
            {
                s += v[i];
                while (s > T)
                {
                    s -= v[j];
                    j++;
                }
                answer += (i - j + 1);
            }
        }
    cout << answer << "\n";
}
int main()
{
    Citire();
    Rezolvare();
    return 0;
}