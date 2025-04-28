#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define fi first
#define se second
#define inf (INT_MAX/2-1)
#define infl (1LL<<61)
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) begin(a),end(a)
#define y0 y5656
#define y1 y7878
#define aaa (void)system("read -r -p \"Press enter to continue...\" key");
#define dbg(x) std::cerr<<(#x)<<": "<<(x)<<'\n',aaa
#define dbga(x,n) std::cerr<<(#x)<<"[]: ";for(int _=0;_<n;_++)std::cerr<<x[_]<<' ';std::cerr<<'\n',aaa
#define dbgs(x) std::cerr<<(#x)<<"[stl]: ";for(auto _:x)std::cerr<<_<<' ';std::cerr<<'\n',aaa
#define dbgp(x) std::cerr<<(#x)<<": "<<x.fi<<' '<<x.se<<'\n',aaa
#define dbgsp(x) std::cerr<<(#x)<<"[stl pair]:\n";for(auto _:x)std::cerr<<_.fi<<' '<<_.se<<'\n';aaa
#define maxn 5000
using namespace std;
ifstream fin("veri.in");
ofstream fout("veri.out");
vi g[maxn+5], gt[maxn+5];
int ds[maxn+5], da[maxn+5], db[maxn+5], d[maxn+5];
int prewS[maxn+5], prewA[maxn+5], prewB[maxn+5], prew[maxn+5];
void bf(int n, int src, vi (&gh)[maxn+5], int *d, int *p) {
    queue<int> qu;
    fill(d+1, d+n+1, inf);
    fill(p+1, p+n+1, -1);
    d[src] = 0;
    qu.push(src);
    while (!qu.empty()) {
        int nod = qu.front();
        qu.pop();
        for (int nn: gh[nod]) {
            if (d[nn] > d[nod] + 1) {
                d[nn] = d[nod] + 1;
                p[nn] = nod;
                qu.push(nn);
            }
        }
    }
}
vi genWay(int *p, int src, int dst, bool inv = true) {
    vi sol(1, dst);
    while (sol.back() != src) {
        sol.pb(p[sol.back()]);
    }
    if (inv) {
        reverse(all(sol));
    }
    return sol;
}
void afis(vi x) {
    assert(sz(x) > 0);
    fout << sz(x) - 1 << '\n';
    for (int y: x) fout << y << ' ';
    fout << '\n';
}
int main() {
    int tip; fin >> tip;
    int n, m; fin >> n >> m;
    int s, a, b; fin >> s >> a >> b;
    int i, j, z;
    for (i = 1; i <= m; i++) {
        int x, y; fin >> x >> y;
        g[x].pb(y);
        gt[y].pb(x);
    }
    bf(n, s, g, ds, prewS);
    if (a == b) {
        if (tip == 1) {
            fout << ds[a];
        } else {
            afis(genWay(prewS, s, a));
            afis({a});
            afis({a});
        }
        return 0;
    }
    bf(n, a, gt, da, prewA);
    bf(n, b, gt, db, prewB);
    int ans = inf, ansCyc = inf, bestI = -1, bestJ = -1;
    for (i = 1; i <= n; i++) {
        ///s -> i -> (ciclu) -> i -> a/b.
        if (ds[i] < inf && da[i] < inf && db[i] < inf) {
            bf(n, i, g, d, prew);
            for (int nn: gt[i]) {
                if (d[nn] < inf && ans > ds[i] + d[nn] + 1 + max(da[i], db[i]) ||
                    (ans == ds[i] + d[nn] + 1 + max(da[i], db[i]) && ansCyc > ds[i] + d[nn] + 1)) {
                    ans = ds[i] + d[nn] + 1 + max(da[i], db[i]);
                    ansCyc = ds[i] + d[nn] + 1; ///poate am s -> .. j .. -> i -> (ciclu care trece si prin j?) -> i -> a/b.
                    bestI = i;
                    bestJ = nn;
                }
            }
        }
    }
    if (tip == 1) {
        fout << ans;
    } else {
        bf(n, bestI, g, d, prew);
        vi waySI = genWay(prewS, s, bestI);
        waySI.pop_back();
        vi wayII = genWay(prew, bestI, bestJ);
        wayII.pb(bestI);
        waySI.insert(waySI.end(), all(wayII));
        afis(waySI);
        afis(genWay(prewA, a, bestI, false));
        afis(genWay(prewB, b, bestI, false));
    }
    return 0;
} 