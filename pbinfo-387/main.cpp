#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, d;
    long long S = 0;
    cin >> n;
    for (d = 1; d * d < n; d++)
        if (n % d == 0) {
            if (d % 2 == 1) S = S + d;
            if (n / d % 2 == 1) S = S + n / d;
        }
    if (d * d == n) if (d % 2 == 1) S = S + d;
    cout << S;
    return 0;
}