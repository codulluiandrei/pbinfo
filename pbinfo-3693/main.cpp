#include <bits/stdc++.h>
using namespace std;
int level(int node) {
    int ans = 0;
    while(node) {
        ++ans;
        node >>= 1;
    }
    return ans - 1;
}
int lca(int u, int v) {
    while(v != u) {
        if(v < u)
            swap(u, v);
        v >>= 1;
    }
    return u;
}
void test_case() {
    int Q;
    cin >> Q;
    while(Q--) {
        int u, v;
        cin >> u >> v;
        cout << level(u) + level(v) - (level(lca(u, v)) << 1) << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--)
        test_case();
}