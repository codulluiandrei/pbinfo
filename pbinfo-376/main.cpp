#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, d;
    long long S = 0;
    cin >> n;
    for (d = 1; d * d < n; d++) if (n % d == 0) S = S + d + n / d;
    if (d * d == n) S = S + d;
    cout << S;
    return 0;
}