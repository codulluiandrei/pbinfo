#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int val1 = 0, val2 = 0;
    while (n != 0) {
        if (n % 2 == 0) val1++;
        else val2++;
        n = n / 2;
    } cout << val1 << " " << val2;
    return 0;
}