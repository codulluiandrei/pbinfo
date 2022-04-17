#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, c, produs = 1; cin >> n;
    bool adv = false;
    while (n) {
        c = n % 10;
        if (c % 2 == 1) {
            produs = produs * c;
            adv = true;
        }
        n = n / 10;
    } if (adv) cout << produs;
    else cout << -1;
    return 0;
}