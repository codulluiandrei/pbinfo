#include <bits/stdc++.h>
using namespace std;

ifstream fin("secv011.in");
ofstream fout("secv011.out");

int main() {
    int n; fin >> n;
    vector<int> frq(3 * n + 1);

    frq[n] = 1;
    int ps = 0;

    int64_t sol = 0;
    for (int i = 1; i <= n; i++) {
        bool x; fin >> x; ps += x;
        sol += frq[2 * i - 3 * ps + n]++;
    }
    fout << sol << '\n';

    fout.close();
    return 0;
}
