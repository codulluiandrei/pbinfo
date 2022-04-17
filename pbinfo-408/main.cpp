#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n;
    x = 0;
    while(n) {
        x = 10 * x + n % 10; n = n / 10;
    } int d;
    for (d = 1; d * d < x; d++) if (x % d == 0) n = n + 2;
    if (d * d == x) n++; 
    cout << n;
    return 0;
}