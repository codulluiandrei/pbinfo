#include <bits/stdc++.h>
using namespace std;
bitset<1000005> b;
bitset<1000005> a;
int prime[80000], k, n;
void Ciur(int n)
{
    int i, j;
    for (i = 4; i <= n; i += 2)
        b[i] = 1;
    for (i = 3; i * i <= n; i += 2)
        if (b[i] == 0)
            for (j = i * i; j <= n; j = j + 2 * i)
                b[j] = 1;
    k = 1;
    prime[1] = 2;
    for (i = 3; i <= n; i += 2)
        if (b[i] == 0) prime[++k] = i;
}
void AproapePrime()
{
    int i, j;
    for (i = 1; i <= k; i++)
        for (j = i; j <= k && 1LL * prime[i] * prime[j] <= 100000; j++)
            a[ prime[i] * prime[j] ] = 1;
    int cnt = 0;
    for (int i = 4; i <= 100000; i++)
        if (a[i] == 1) cnt++;
}
void CitireAfisare()
{
    int i;
    cin >> n;
    for (i = 4; i <= 100000; i++)
        if (a[i] == 1)
        {
            n--;
            if (n == 0)
            {
                cout << i;
                return;
            }
        }
}
int main()
{
    Ciur(100000);
    AproapePrime();
    CitireAfisare();
    return 0;
}