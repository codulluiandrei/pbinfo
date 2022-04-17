#include <bits/stdc++.h>
using namespace std;
int freq[1000001];
int main() {
    int n, m, mat[101][101], v[10000], p = 0, maxim = 0;
    cin >> n >> m;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            v[p] = mat[i][j];
            p++;
            freq[mat[i][j]]++;
            if (freq[mat[i][j]] > maxim) maxim = freq[mat[i][j]];
        }
    } sort(v, v + p);
    for (int i = 0; i < p; i++) {
        if (freq[v[i]] == maxim && v[i] != v[i - 1])
            cout << v[i] << " ";
    }
}