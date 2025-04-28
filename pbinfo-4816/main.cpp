#include <cassert>
#include <iostream>
#include <limits>
#include <set>
using namespace std;
const int MAX_N = (int)1e9;
const int MAX_M = (int)1e5;
int n, m;
int ans;
set<pair<int, int>> s;
void addInterval(int left, int right) {
    ans += right - left + 1;
    s.insert({left, right});
}
void removeInterval(set<pair<int, int>>::iterator it) {
    ans -= it->second - it->first + 1;
    s.erase(it);
}
void splitIntersections(int pos) {
    auto entry = s.lower_bound({pos + 1, numeric_limits<int>::min()});
    if (entry != s.begin()) {
        entry = prev(entry);
    }
    if (entry == s.end()) {
        return;
    }
    int left = entry->first, right = entry->second;
    if (pos > left && pos <= right) {
        removeInterval(entry);
        addInterval(left, pos - 1);
        addInterval(pos, right);
    }
}
int main() {
    assert(freopen("experimente.in", "r", stdin));
    assert(freopen("experimente.out", "w", stdout));
    cin >> n >> m;
    assert(1 <= n && n <= MAX_N);
    assert(1 <= m && m <= MAX_M);
    addInterval(0, n-1);
    for (int i = 1; i <= m; ++i) {
        int left, right;
        cin >> left >> right;
        assert(0 <= left && left < n);
        assert(0 <= right && right < n);
        if (i > 1) {
            left = (left + ans) % n;
            right = (right + ans) % n;
        }
        splitIntersections(left);
        splitIntersections(right + 1);
        if (left <= right) {
            while (!s.empty() && s.begin()->second < left) {
                removeInterval(s.begin());
            }
            while (!s.empty() && prev(s.end())->first > right) {
                removeInterval(prev(s.end()));
            }
            cout << ans << "\n";
        } else {
            auto startIt = s.lower_bound({right + 1, numeric_limits<int>::min()});
            auto endIt = startIt;
            while (endIt != s.end() && endIt->second < left) {
                ans -= endIt->second - endIt->first + 1;
                endIt = next(endIt);
            }
            s.erase(startIt, endIt);
            cout << ans << "\n";
        }
    }
    return 0;
}