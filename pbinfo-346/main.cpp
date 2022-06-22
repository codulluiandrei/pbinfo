#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int maxim = 0, apare = 0;
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        if (temp > maxim) {
            maxim = temp;
            apare = 1;
        } else if (temp == maxim) { apare++; }
    } cout << maxim << " " << apare;
    return 0;
}