#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, v[1001];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (j % 2 == 0) cout << v[i] << " ";
            else cout << v[n - i + 1] << " ";
        cout << endl;
    } return 0;
}