#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, p, q; cin >> a >> b; p = a, q = b;
    while (a % b) {
        int r = a % b;
        a = b;
        b = r;
    } cout << p*q/b << endl;
    return 0;
}