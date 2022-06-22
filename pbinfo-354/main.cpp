#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int maxim = -1000000000;
    for (int i = 1; i <= n; ++i) {
        int temp; cin >> temp;
        if (temp > maxim) maxim = temp;
    } cout << maxim;
    return 0;
}