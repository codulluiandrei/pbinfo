#include <cstdio>
#include <vector>
#include <fstream>
#include <cassert>
using namespace std;
int main() {
    ifstream fin("rosii_mici.in");
    ofstream fout("rosii_mici.out");
    int n, m, q;
    fin >> n >> m >> q;
    assert(1 <= n && n <= 1000);
    assert(1 <= m && m <= 1000);
    assert(1 <= q && q <= 100000);
    vector<vector<int>> positions(n * m + 5);
    vector<int> minn(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            fin >> x;
            assert(minn[j] <= x);
            minn[j] = x;
            assert(1 <= x && x <= n*m);
            positions[x].push_back(j);
        }
    }
    vector<int>height(m + 1, 0), sum(n + 1, 0);
    vector<int>ans(n * m + 5, 0);
    int sol = 0;
    for (int val = 1;val <= n*m; ++val) {
        for(auto j: positions[val]) {
            height[j]++;
            sum[height[j]]++;
            sol = max(sol,sum[height[j]] * height[j]);
        }
        ans[val] = sol;
    }
    for (int i = 1; i <= n*m; i++) 
        ans[i] = max(ans[i-1], ans[i]);
    while(q-- > 0) {
        int x;
        fin >> x;
        assert(1 <= x && x <= n*m);
        fout << ans[x] << "\n";
    }
    return 0;
} 