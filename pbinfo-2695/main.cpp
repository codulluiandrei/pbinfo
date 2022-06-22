#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n, r, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        r = cbrt(x);
        if (r * r * r == x)
            cout << "DA" << '\n';
        else
            cout << "NU" << '\n';
    } return 0;
}