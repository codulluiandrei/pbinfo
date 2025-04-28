// Popa Sebastian
#include <bits/stdc++.h>
using namespace std;
const int mod = 9 + 1e9;
const int nmax = 5 + 1e5;
ifstream f("fotbal.in");
ofstream g("fotbal.out");
struct str
{
    int st, dr, tip;
    bool operator<(const str &other) const
    {
        return st < other.st;
    }
} v[nmax];
vector<long> fact(nmax, 1), inv_fact(nmax, 1);
void precompute();
int nCk(const int &, const int &);
int n, k, rez, c[2];
priority_queue<pair<int, bool>> pq;
int main()
{
    precompute();
    f >> n >> k;
    for (int i = 1; i <= n; i++)
        f >> v[i].st >> v[i].dr >> v[i].tip;
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; i++)
    {
        while (!pq.empty() && -pq.top().first < v[i].st)
            c[pq.top().second]--, pq.pop();
        if (pq.size() >= k - 1 && c[!v[i].tip])
            rez = (rez + nCk(pq.size(), k - 1)) % mod,
            rez = (rez - nCk(c[v[i].tip], k - 1) + mod) % mod;
        c[v[i].tip]++;
        pq.push({-v[i].dr, v[i].tip});
    }
    g << rez;
    return 0;
}
void precompute()
{
    vector<int> inv(nmax, 1);
    for (int i = 2; i < nmax; i++)
    {
        inv[i] = mod - (1ll * (mod / i) * inv[mod % i]) % mod;
        fact[i] = (1ll * fact[i - 1] * i) % mod;
        inv_fact[i] = (1ll * inv_fact[i - 1] * inv[i]) % mod;
    }
}
int nCk(const int &n, const int &k)
{
    if (!n || k > n)
        return 0;
    if (!k || k == n)
        return 1;
    static int rez;
    rez = (1ll * fact[n] * inv_fact[k]) % mod;
    return (1ll * rez * inv_fact[n - k]) % mod;
}