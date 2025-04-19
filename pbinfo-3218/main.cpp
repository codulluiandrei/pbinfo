#include <bits/stdc++.h>
using namespace std;
bitset<3300003> a;
int prime[1000000], k;
void Ciur(int n)
{
    int i, j;
    for (i = 3; i * i <= n; i += 2)
        if (a[i] == 0)
            for (j = i * i; j <= n; j = j + i + i)
                a[j] = 1;
    prime[1] = 2;
    k = 1;
    for (i = 3; i <= n; i += 2)
        if (a[i] == 0) prime[++k] = i;
}
int NrDiv(long long n)
{
    long long d = 2;
    int i = 1, e, ans = 1;
    while (n > 1 && d * d <= n)
    {
        e = 0;
        while (n % d == 0)
        {
            e++;
            n /= d;
        }
        if (e > 0) ans *= (e + 1);
        d = prime[++i];
    }
    if (n > 1) ans *= 2;
    return ans;
}
int main()
{
    long long x;
    int n;
    Ciur(3200000);
    ifstream fin("nrdiv.in");
    ofstream fout("nrdiv.out");
    fin >> n;
    while (n--)
    {
        fin >> x;
        fout << NrDiv(x) << "\n";
    }
    fout.close();
    return 0;
}