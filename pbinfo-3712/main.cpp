#include <bits/stdc++.h>
// Solutia "brute-force" - Lorintz Alexandru
// 40 de puncte
// Complexitate: O(Q * N * log(N))
using namespace std;
ifstream fin("median_query.in");
ofstream fout("median_query.out");
int main() {
    int N, Q;
    fin >> N >> Q;
    vector<int> a(N + 1);
    for(int i = 1; i <= N; ++i)
        fin >> a[i];
    while(Q--) {
        int l, r;
        fin >> l >> r;
        vector<int> v{0};
        for(int i = l; i <= r; ++i)
            v.emplace_back(a[i]);
        sort(v.begin() + 1, v.end());
        fout << v[(r - l + 2) >> 1] << '\n';
    }
}