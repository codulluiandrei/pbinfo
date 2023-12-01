#include <bits/stdc++.h>

using namespace std;

long long ret = 0;
int n, t, v[10000] = {};

ifstream fin("bossfight.in");
ofstream fout("bossfight.out");

int main() {
    fin >> n >> t;
    for (int i = 0; i < n; ++i) fin >> v[i];

    vector<int> rhs, lhs(v, v + n);
    sort(begin(lhs), end(lhs));

    for (int i = n - 1; i >= 0; --i) {
        lhs.erase(lower_bound(begin(lhs), end(lhs), v[i]));

        for (int x = 0, y = lhs.size(); x < rhs.size(); ++x) {
            while (y > 0 && (lhs[y - 1] >= v[i] || lhs[y - 1] + v[i] > t - rhs[x])) --y;
            if (v[i] < rhs[x]) ret += y;
        }

        rhs.insert(lower_bound(begin(rhs), end(rhs), v[i]), v[i]);
    }

    fout << ret << endl;
}
 