#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, b, temp1, temp2 = 0, temp3 = 1, S = 0;
    cin >> b >> n;
    while (temp2 < n - 1) {
        temp3 = temp3 * b;
        temp2++;
    } for (int i = 1; i <= n; i++) {
        cin >> temp1;
        S = S + temp1 * temp3;
        temp3 = temp3 / b;
    } cout << S;
    return 0;
}