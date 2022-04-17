#include <bits/stdc++.h>
using namespace std;
long long n, k, i, s, c, r;
int main() {
    cin >> n >> k;
    c = n / k;
    r = n % k;
    s = c * (k - 1) * k / 2 + r * (r + 1) / 2;
    cout << s;
    return 0;
}