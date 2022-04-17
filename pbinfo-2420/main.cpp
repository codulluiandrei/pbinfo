#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, S = 0; cin >> n;
    for (int i = 2; i < n; i++) {
        S = S + n / i;    
    } if (n == 1) cout << n;
    else cout << S + n + 1;
    return 0;    
}