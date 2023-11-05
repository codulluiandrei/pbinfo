#include <bits/stdc++.h>
using namespace std;
int main() {
    bool ok = false;
    long long int n;
    cin >> n;
    for (long long int i = 1; i * i <= n / 2 && !ok; ++i) {
        long long int x = i * i;
        long long int y = n - x;
        long long int j = sqrt(y);
        if (j * j == y && !ok)
            cout << min(y, x) << " " << max(x, y), ok = true;
    } if (ok == false)cout << "NU";
    return 0;
}