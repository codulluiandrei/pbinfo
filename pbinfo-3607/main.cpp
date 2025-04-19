#include <bits/stdc++.h>
using namespace std;
ifstream fin("run.in");
ofstream fout("run.out");
typedef long long ll;
const int NMAX = 1e5;
int a[NMAX + 1], suf[NMAX + 2];
ll s[NMAX + 2], v[NMAX];
int main() {
    int N, M, K;
    fin >> N >> M >> K;
    for(int i = 1; i <= N; ++i)
        fin >> a[i];
    for(int i = N; i > 0; --i) {
        suf[i] = suf[i + 1] + a[i];
        s[i] = s[i + 1] + a[i] * (N - i + 1);
    }
    for(int i = 0; i < M; ++i) {
        int l, r;
        fin >> l >> r;
        v[i] = s[l] - s[r + 1] - (ll)(N - r) * (suf[l] - suf[r + 1]);
    }
    sort(v, v + M);
    ll ans = 0;
    for(int i = 0; i < K; ++i)
        ans += v[i];
    fout << ans;
}