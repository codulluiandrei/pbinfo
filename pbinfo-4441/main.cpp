#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e4 + 5;
typedef bitset<NMAX> Bitset;
void pre_dfs(int nod, int fth, vector<vector<int>> &edg, vector<int> &sz) {
    sz[nod] = 1;
    for (auto nxt: edg[nod]) {
        if (nxt == fth) continue;
        pre_dfs(nxt, nod, edg, sz);
        sz[nod] += sz[nxt];
    }
}
void solve_dfs(int nod, int fth, int K, vector<vector<int>> &edg, vector<int> &sz, Bitset &above, vector<int> &ans) {
    if (K <= 0)
        return;
    if (above[K - 1])
        ans.push_back(nod);
    sort(begin(edg[nod]), end(edg[nod]),
         [&](int x, int y) { return sz[x] < sz[y]; });
    Bitset dp = above;
    int lst = -1;
    for (auto nxt: edg[nod]) {
        if (nxt == fth) continue;
        if (sz[nxt] != lst) {
            lst = sz[nxt];
            dp = above;
            for (auto son: edg[nod]) {
                if (son == fth || son == nxt) continue;
                dp |= dp << sz[son];
            }
        }
        solve_dfs(nxt, nod, K - 1, edg, sz, dp, ans);
    }
}
void pre_bfs_1(int nod, int fth, vector<vector<int>> &edg, vector<int> &h) {
    for (auto nxt: edg[nod]) {
        if (nxt == fth) continue;
        h[nxt] = h[nod] + 1;
        pre_bfs_1(nxt, nod, edg, h);
    }
}
void pre_bfs_2(int nod, int fth, int H, vector<vector<int>> &edg, vector<int> &h, vector<int> &sz) {
    sz[nod] = h[nod] == H;
    for (auto nxt: edg[nod]) {
        if (nxt == fth) continue;
        pre_bfs_2(nxt, nod, H, edg, h, sz);
        sz[nod] += sz[nxt];
    }
}
void solve_bfs(int nod, int fth, int K, int H, vector<vector<int>> &edg, vector<int> &sz, vector<int> &h, Bitset &above,
               vector<int> &ans) {
    if (sz[nod] == 0)
        return;
    if (K <= 0)
        return;
    if (above[K - 1] && h[nod] == H)
        ans.push_back(nod);
    sort(begin(edg[nod]), end(edg[nod]),
         [&](int x, int y) { return sz[x] < sz[y]; });
    Bitset dp = above;
    int lst = -1;
    for (auto nxt: edg[nod]) {
        if (nxt == fth) continue;
        if (sz[nxt] == 0) continue;
        if (sz[nxt] != lst) {
            lst = sz[nxt];
            dp = above;
            for (auto son: edg[nod]) {
                if (son == fth || son == nxt) continue;
                if (sz[son] != 0)
                    dp |= dp << sz[son];
            }
        }
        solve_bfs(nxt, nod, K, H, edg, sz, h, dp, ans);
    }
}
void solve_test() {
    int op, N, K;
    scanf("%d%d%d", &op, &N, &K);
    vector<vector<int> > edg(N, vector<int>());
    for (int i = 1; i < N; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        edg[x].push_back(y);
        edg[y].push_back(x);
    }
    if (op == 1) {   // DFS
        vector<int> sz(N, 0);
        pre_dfs(0, -1, edg, sz);
        Bitset start;
        start[0] = 1;
        vector<int> ans;
        solve_dfs(0, -1, K, edg, sz, start, ans);
        sort(begin(ans), end(ans));
        for (auto x: ans)
            printf("%d ", x + 1);
        printf("\n");
    } else if (op == 2) {    // BFS
        vector<int> sz(N, 0), h(N, 0);
        pre_bfs_1(0, -1, edg, h);
        vector<int> cnt(N, 0);
        for (int i = 0; i < N; i++) cnt[h[i]]++;
        int H = 0;
        for (H = 0; H < N; H++) {
            if (cnt[H] >= K) break;
            K -= cnt[H];
        }
        pre_bfs_2(0, -1, H, edg, h, sz);
        Bitset start;
        start[0] = 1;
        vector<int> ans;
        solve_bfs(0, -1, K, H, edg, sz, h, start, ans);
        sort(begin(ans), end(ans));
        for (auto x: ans)
            printf("%d ", x + 1);
        printf("\n");
    }
}
int main() {
    freopen("keidei.in", "r", stdin);
    freopen("keidei.out", "w", stdout);
    solve_test();
    return 0;
} 