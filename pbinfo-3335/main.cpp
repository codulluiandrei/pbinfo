#include <bits/stdc++.h>
using namespace std;
long long i, c, p, x, k, r;
int main() {
    cin >> c >> p;
    x = c - p * (p - 1) / 2;
    if (x < p)cout << c << "\n";
    else {
        k = x / p;
        r = x - k * p;
        cout << r << "\n";
    } return 0;
}