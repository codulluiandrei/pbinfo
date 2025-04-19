#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int NMAX = 1e5 + 5;
const int ELEMMAX = 1e6 + 5;
vector<vector<int>> fact(ELEMMAX);
int n;
vector<long long> a(NMAX);
vector<vector<int>> pos(ELEMMAX);
vector<vector<long long>> presum(ELEMMAX);
vector<vector<long long>> sufsum(ELEMMAX);
void ciur() {
    for (int i = 2; i < ELEMMAX; i++) {
        if (fact[i].empty()) {
            for (int j = i; j < ELEMMAX; j += i) {
                fact[j].push_back(i);
            }
        }
    }
}
void precalculare() {
    for (int i = 2; i < ELEMMAX; i++) {
        sort(sufsum[i].rbegin(), sufsum[i].rend());
        unsigned long long sz = presum[i].size();
        for (int j = 1; j < sz; j++) {
            presum[i][j] += presum[i][j - 1];
            sufsum[i][j] += sufsum[i][j - 1];
        }
    }
    for (int i = 2; i <= n; i++) {
        a[i] += a[i - 1];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ciur();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int factor: fact[a[i]]) {
            presum[factor].push_back(a[i]);
            sufsum[factor].push_back(a[i]);
            pos[factor].push_back(i);
        }
    }
    precalculare();
    int m;
    cin >> m;
    while (m--) {
        int p, q;
        cin >> p >> q;
        int cnt = -1;
        int st = 0;
        int dr = pos[p].size() - 1;
        while (st <= dr) {
            int mij = st + (dr - st) / 2;
            if (pos[p][mij] <= q) {
                cnt = mij;
                st = mij + 1;
            } else {
                dr = mij - 1;
            }
        }
        long long sol = a[q];
        if (cnt >= 0) {
            sol += sufsum[p][cnt] - presum[p][cnt];
        }
        cout << sol << '\n';
    }
    return 0;
} 