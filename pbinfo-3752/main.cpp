/*
   O(nr_tiplete x N) cu c*c : gcd(a, b)
   nr_triplete calculate in O(nr_div^2), N - nr. de valori distincte
*/
# include <bits/stdc++.h>
using namespace std;
ifstream f("cvintete.in");
ofstream g("cvintete.out");
const int MOD = 1e9 + 7;
int s[100010];
int D[20001];
int ap[100010];
int apt[20001];
long long p[100010];
struct triplet
{
    int x,y,z;
} T[20001];
int n, N, M, K;
long long nr, d;
void formtrip()
{
    int i, j, k;
    for(k=K; k>=2; k--)
    {
        i = 1, j = k - 1;
        while (i < j)
        {
            long long x = 1LL * D[i] * D[j] * D[k];
            if (x == d)
            {
                T[++N] = {D[i], D[j], D[k]};
                apt[N] = (ap[D[i]] * ap[D[j]] * ap[D[k]]);
                i++, j--;
            }
            else if (x < d) i++;
                       else j--;
        }
    }
}
long long gcd(long long a, long long b)
{
    while (b)
    {
        long long r = a % b;
        a = b; b = r;
    }
    return a;
}
long long ec(int a, int b, int c)
{
    int nr = 0, i = 1, j = n;
    j = lower_bound(p, p+n+1, c / b) - p;
    if (j < 0 || j > n) j = n;
    while (i <= n && j > 0)
    {
        long long x = 1LL * a * p[i] + 1LL * b * p[j];
        if (x == c)
        {
            if (s[i] != s[j])
            {
                nr = (nr + 1LL * (ap[s[i]] * ap[s[j]]));
            }
            i++, j--;
        }
        else if (x < c) i++;
                   else j--;
    }
    return nr;
}
int main()
{
    int i, j, k;
    long long x, y = 0;
    f >> n >> d;
    n = 0;
    while (f >> x)
    {
        y = x;
        if (ap[x] == 0)
        {
            s[++n] = x;
            p[n] = 1LL * x * x;
            ap[x] = 1;
            if (d % x == 0) D[++K] = x;
        } else ap[x]++;
    }
    formtrip();
    for(i=1; i<=N; i++)
    {
        long long a, b, c;
        a = T[i].x;
        b = T[i].y;
        c = T[i].z * T[i].z;
        if (c % gcd(a, b) == 0)
        {
            x = ec(a, b, c);
            nr = ( nr + 1LL * apt[i] * x );
        }
    }
    g << nr % MOD;
    return 0;
}