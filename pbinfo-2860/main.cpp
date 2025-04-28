#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
char s[nmax];
long long dp[nmax];
int n;
/// returneaza 0 daca numarul nu e prim,
/// sau returneaza numarul prim
int Prim(int x, int y)
{
    int n = 0, i;
    for (i = x; i <= y; i++)
        n = n * 10 + s[i] - '0';
    if (n <= 1) return 0;
    if (n == 2) return n;
    if (n % 2 == 0) return 0;
    for (i = 3; i * i <= n; i += 2)
        if (n % i == 0) return 0;
    return n;
}
void Dinamica()
{
    int i, j, val;
    dp[0] = 0;
    for (i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (j = max(1, i - 5); j <= i; j++)
        {
            val = Prim(j, i);
            dp[i] = max(dp[i], dp[j - 1] + val);
        }
    }
}
int main()
{
    cin >> (s + 1);
    n = strlen(s + 1);
    Dinamica();
    cout << dp[n] << "\n";
    return 0;
}