#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream cin("amat.in");
    ofstream cout("amat.out");
    int task; cin >> task;
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    if (task == 1) {
        const int kMax = 5000;
        vector<int> lt(kMax, -1), rt(kMax, -1), up(kMax, -1), dw(kMax, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = a[i][j] + 2000;
                if (lt[val] == -1 || lt[val] > j) lt[val] = j;
                if (rt[val] == -1 || rt[val] < j) rt[val] = j;
                if (up[val] == -1 || up[val] > i) up[val] = i;
                if (dw[val] == -1 || dw[val] < i) dw[val] = i;
            }
        }
        tuple<int, int, int, int> best = make_tuple(-1, -1, -1, -1);
        for (int i = 0; i < kMax; ++i) {
            tuple<int, int, int, int> now = make_tuple(
                (rt[i] - lt[i] + 1) * (dw[i] - up[i] + 1), up[i], lt[i], i);
            best = max(best, now);
        }
        int col = get<3>(best);
        cout << up[col] + 1 << " " << lt[col] + 1 << " " << dw[col] + 1 << " " << rt[col] + 1 << endl;
    } else {
        int q, k; cin >> q >> k;
        vector<tuple<int, int, int, int, int>> ops;
        for (int i = 0; i < q; ++i) {
            int u, l, d, r, x; cin >> u >> l >> d >> r >> x;
            ops.emplace_back(u, l, d, r, x);
        }
        int sol = 0;
        for (int step = 1, adv = 1; step; adv ? step *= 2 : step /= 2) {
            if (sol + step > q) { adv = 0; }
            else {
                vector<vector<int>> mars(n + 1, vector<int>(m + 1, 0));
                for (int i = sol; i < sol + step; ++i) {
                    int u, l, d, r, x; tie(u, l, d, r, x) = ops[i];
                    mars[u - 1][l - 1] += x;
                    mars[u - 1][r] -= x;
                    mars[d][l - 1] -= x;
                    mars[d][r] += x;
                } 
                bool bad = false;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        if (i > 0) mars[i][j] += mars[i - 1][j];
                        if (j > 0) mars[i][j] += mars[i][j - 1];
                        if (i > 0 && j > 0) mars[i][j] -= mars[i - 1][j - 1];
                        if (mars[i][j] + a[i][j] < k) {
                            bad = true;
                        }
                    }
                }   
                /* 
                cerr << sol + step << endl;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j)
                        cerr << a[i][j] + mars[i][j] << " ";
                    cerr << endl;
                }
                */
                if (!bad) { adv = 0; continue; }
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        a[i][j] += mars[i][j];
                    }
                }
                sol += step;
            }
        }
        assert(sol < q);
        cout << sol + 1 << endl;
    }
    return 0;
}