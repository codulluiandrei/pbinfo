#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int i2 = 1; i2 <= n - i; i2++) cout << " ";
        for (int i2 = 1; i2 <= 2 * i - 1; i2++) cout << i;
        cout << '\n';
    } for (int i = 1; i < n; i++) {
        for (int i2 = 1; i2 <= i; i2++) cout << " ";  
        for (int i2 = 1; i2 <= 2 * (n - i) - 1; i2++) cout << n - i;
        cout << '\n';
    } return 0;
}