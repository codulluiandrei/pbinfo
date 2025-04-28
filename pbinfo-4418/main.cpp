#include <bits/stdc++.h>
using namespace std;
const int NR = 200000 + 10;
int c, n, k;
int a[NR];
long long sp[NR];
signed main() {
    ifstream in("planor.in");
    ofstream out("planor.out");
    in >> c >> n >> k;
    for (int i = 1; i <= n; ++i) {
        in >> a[i];
        sp[i] = sp[i - 1] + a[i];
    }
    if (c == 1) {
        long long maxi = -1e16;
        for (int i = 1; i <= k; ++i) {
            maxi = max(maxi, sp[i]);
        }
        out << maxi << '\n';
        return 0;
    }
    if (c == 2) {
        long long best = -1e16;
        for (int i = k; i <= n; ++i) {
            best = max(best, sp[i] - sp[i - k]);
        }
        out << best << '\n';
        return 0;
    }
    deque<int> dq;
    long long best = -1e16;
    for (int i = 1; i <= n; ++i) {
        best = max((long long) a[i], best);
    }
    dq.push_back(0);
    for (int i = 1; i <= n; ++i) {
        while (!dq.empty() && sp[dq.back()] > sp[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (!dq.empty() && dq.front() == i - k - 1) {
            dq.pop_front();
        }
        if (dq.size() > 1)
            best = max(best, sp[i] - sp[dq.front()]);
    }
    out << best << '\n';
    return 0;
} 