/* Autor: Andrei Arhire, Universitatea A.I. Cuza, Iași
 * Complexitate: O(NlogN)
 */
#include <bits/stdc++.h>

using namespace std;

struct fraction {
    int a, b, c, i;
} v[1000001];
int n;

bool cmp(fraction i, fraction j) {
    if (i.a % 2 != j.a % 2) {
        return i.a % 2 > j.a % 2;
    }
    if (i.a % 2 == 1) {
        return 1LL * i.b * j.c > 1LL * j.b * i.c;
    }
    return 1LL * i.b * j.c < 1LL * j.b * i.c;
}


signed main() {
    deque<fraction> dq;
    ifstream in("colibri.in");
    ofstream out("colibri.out");
    in >> n;
    for (int i = 1; i <= n; ++i) {
        in >> v[i].a >> v[i].b >> v[i].c;
        v[i].i = i;
    }
    sort(v + 1, v + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        dq.push_back(v[i]);
    }
    vector<fraction> sol;
    while (dq.size() > 1) {
        fraction fr1 = dq.front();
        dq.pop_front();
        fraction fr2 = dq.front();
        dq.pop_front();
        if (fr1.a % 2 == 0 || fr2.a % 2 == 0 || 1LL * fr1.b * fr2.b < 1LL * fr1.c * fr2.c) {
            dq.push_front(fr2);
            dq.push_front(fr1);
            break;
        }
        sol.emplace_back(fr1);
        sol.emplace_back(fr2);
    }
    while (!dq.empty() && dq.back().a % 2 == 0 && dq.back().b >= dq.back().c ) {
        sol.emplace_back(dq.back());
        dq.pop_back();
    }
    if (!sol.empty()) {
        string ans(n, '0');
        for (auto it : sol) {
            ans[it.i - 1] = '1';
        }
        out << ans << '\n';
        return 0;
    }
    if (dq.size() == 1) {
        out << 1 << '\n';
        return 0;
    }
    auto fr1 = dq.front();
    dq.pop_front();
    auto fr2 = dq.front();
    auto fr3 = dq.back();
    if (1LL * fr1.b * fr2.b * fr3.c > 1LL * fr3.b * fr1.c * fr1.c) {
        sol.emplace_back(fr1);
        sol.emplace_back(fr2);
    } else {
        sol.emplace_back(fr3);
    }
    string ans(n, '0');
    for (auto it : sol) {
        ans[it.i - 1] = '1';
    }
    out << ans << '\n';

    return 0;
}