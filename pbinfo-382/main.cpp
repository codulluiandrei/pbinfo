#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    int multiplu;
    cin >> k >> n;
    multiplu = k / n;
    if (k - multiplu * n > n * (multiplu + 1) - k) cout << n * (multiplu + 1);
    else cout << multiplu * n;
    return 0;
}