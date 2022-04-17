#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    while (a % b) {
        int r = a % b;
        a = b;
        b =r;
    } if (b == 1) cout << "PIE";
    else cout << "NOPIE";
    return 0;
}