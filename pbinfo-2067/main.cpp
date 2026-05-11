#include<bits/stdc++.h>
using namespace std;
typedef pair <int, int> seg;
const int maxn = 1e5 + 10;
int l[maxn], r[maxn];
seg f0[maxn], f[maxn];
seg bsd(seg a, seg b) {
    if(a.first > b.first || (a.first == b.first && a.second < b.second))
        return a;
    return b;
}
int query(int x, int n) {
    return lower_bound(r + 1, r + 1 + n, x) - r;
}
void solve() {
    int j, n, w;
    int L, d, t;
    ifstream cin ("curiosity2.in");
    ofstream cout ("curiosity2.out");
    cin >> L >> d >> t >> n;
    for (int i = 1; i <= n; i++){
        cin >> l[i] >> w;
        r[i] = l[i] + w;
    }
    l[n + 1] = L + 1;
    r[n + 1] = L + 2;
    for (int i = 1; i <= n; i++) {
        f0[i] = bsd(f0[i], f0[i - 1]);
        f[i] = bsd(f[i], {f0[i].first + (r[i] - l[i]) / d, l[i] + (r[i] - l[i]) / d * d });
        int t0 = f[i].second + t;
        j = query(t0, n + 1);
        if(j > n) continue;
        if(l[j] >= t0) {
            f0[j] = bsd(f0[j], {f[i].first, t0 });
            continue;
        }
        f[j] = bsd(f[j], {f[i].first + (r[j] - t0) / d, t0 + (r[j] - t0) / d * d});
        f0[j + 1] = bsd(f0[j + 1], {f[i].first, t0 });
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i].first);
    cout << ans << endl;
}
int main() {
    solve();
    return 0;
}