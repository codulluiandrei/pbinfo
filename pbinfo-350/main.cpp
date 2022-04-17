#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    cout << "{";
    for (int i = 1; i <= n; i++) {
        for (int i2 = 1; i2 < m; i2++) cout << "(" << i << ',' << i2 << "),";
        if (i == n) cout << "(" << i << "," << m << ")";
        else cout << "(" << i << "," << m << "),";   
    } cout << "}";
    return 0;
}