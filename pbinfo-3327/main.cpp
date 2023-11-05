#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    int k = sqrt(n);
    if (k * k == n) k--;
    cout << n - k * k << "\n";
    int nr = k * k;
    for (int i = 1; i <= k; ++i, cout << "\n")
        for (int j = 1; j <= k; ++j)
        	cout << nr << " ", nr--;
    return 0;
}