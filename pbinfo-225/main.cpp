#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= k && j <= k) cout << 1 << " ";
            else if (i <= k && j > k) cout << 2 << " ";
            else if (i > k && j <= k) cout << 3 << " ";
            else cout << 4 << " ";
        } cout << endl;
    } return 0;
}