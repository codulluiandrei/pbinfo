#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x, maxim = -1000, minim = 999999999, d;
    cin >> x;
    for (int i = 1; i <= x; i++) {
        cin >> n;
        if (n < minim) minim = n;
        if (n > maxim) maxim = n;
    } int a = maxim; int b = minim;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    } d = a;
    cout << minim / d << "/" << maxim / d;
    return 0;
}