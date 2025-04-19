/*
 * Problema mostenire (OJI 2019)
 * Complexitate: O(N*(log(S)+log(N))
 * Autor: Lucian Bicsi
 */
#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> Solve(vector<int> v, int k, int need) {
    int n = v.size();
    vector<tuple<int, int, int>> ans;
    int have = 0, start = 0;
    for (int i = 0; i < n; ++i) {
        have += v[i];
        if (have < need) continue;
        if ((int)ans.size() == k - 1 && i != n - 1) continue;
        ans.emplace_back(have, start, i + 1);
        have = 0;
        start = i + 1;
    }
    return ans;
}
int main() {
    ifstream cin("mostenire.in");
    ofstream cout("mostenire.out");
    int n, k; cin >> n >> k;
    assert(k <= 100);
    assert(k <= n);
    assert(n <= 100 * 1000);
    vector<int> v(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        total += v[i];
    }
    assert(total <= 1000 * 1000 * 1000);
    int b = 0, e = total, ans = -1;
    while (b <= e) {
        int m = (b + e) / 2;
        if ((int)Solve(v, k, m).size() == k) {
            ans = m;
            b = m + 1;
        } else e = m - 1;
    }
    assert(ans != -1);
    cout << ans << endl;
    auto sol = Solve(v, k, ans);
    sort(sol.rbegin(), sol.rend());
    vector<tuple<int, int, int>> new_sol;
    for (int i = 0; i < k; ++i) {
        int b, e; tie(ignore, b, e) = sol[i];
        new_sol.emplace_back(b, i, e - b);
    }
    sort(new_sol.begin(), new_sol.end());
    for (auto itr : new_sol) {
        int i, cnt; tie(ignore, i, cnt) = itr;
        cout << i + 1 << " " << cnt << '\n';
    }
    return 0;
}