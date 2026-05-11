/// Solutie - Moca Andrei - 100p
#include <bits/stdc++.h>
using namespace std;
const int Dim(26);
int n, q, op, x, y, res, p2[Dim];
char ch;
string s;
class AINT {
public:
    AINT() {}
    AINT(const int& _n) : n(_n) {
        arb = vector<int>(4 * n);
        Build(1, 1, n);
    }
    inline void Update(const int& pos, const int& val) {
        Update(1, 1, n, pos, val);
    }
    inline int Query(const int& st, const int& dr) {
        return Query(1, 1, n, st, dr);
    }
private:
    inline void Build(int node, int st, int dr) {
        if (st == dr) {
            arb[node] = p2[s[st - 1] - 'a'];
            return;
        }
        int mid = (st + dr) / 2;
        Build(2 * node, st, mid);
        Build(2 * node + 1, mid + 1, dr);
        arb[node] = (arb[2 * node] | arb[2 * node + 1]);
    }
    inline void Update(int node, int st, int dr, const int& pos, const int& val) {
        if (st == dr) {
            arb[node] = val;
            return;
        }
        int mid = (st + dr) / 2;
        if (pos <= mid)
            Update(2 * node, st, mid, pos, val);
        else Update(2 * node + 1, mid + 1, dr, pos, val);
        arb[node] = (arb[2 * node] | arb[2 * node + 1]);
    }
    inline int Query(int node, int st, int dr, const int& l, const int& r) {
        if (l <= st && dr <= r)
            return arb[node];
        int mid = (st + dr) / 2, r1(0), r2(0);
        if (l <= mid)
            r1 = Query(2 * node, st, mid, l, r);
        if (mid < r)
            r2 = Query(2 * node + 1, mid + 1, dr, l, r);
        return (r1 | r2);
    }
private:
    int n;
    vector<int> arb;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    p2[0] = 1;
    for (int i = 1; i < Dim; ++i)
        p2[i] = p2[i - 1] * 2;
    cin >> n >> s >> q;
    AINT ai(n);
    for (int i = 1; i <= q; ++i) {
        cin >> op >> x;
        if (op == 1) {
            cin >> ch;
            ai.Update(x, p2[ch - 'a']);
        }
        else {
            cin >> y;
            cout << __builtin_popcount(ai.Query(x, y)) << '\n';
        }
    }
    return 0;
}