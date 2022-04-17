#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    while (a % b) {
        int temp = a % b;
        a = b; b = temp;
    } for (int d = 1; d <= b; d++) if (b % d == 0) cout << d << " ";
    return 0;
}