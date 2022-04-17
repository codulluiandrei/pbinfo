#include <iostream>
using namespace std;
int main() {
    int n, k, p, a, b, c, d, nr = 0, y;
    cin >> n >> k >> p;
    a = 1; b = 1; c = 2;
    y = p % 124;
    if (a == k) nr++;
    if (b == k) nr++;
    if (c == k) nr++;
    for (int i = 4; i <= n; i++) {
        d = (a + b + c) % 10;
        a = b; b = c; c = d;
        if (d == k) nr++;
    } a = 1; b = 1; c = 2;
    if (y == 1) d = a;
    else if (y == 2) d = b;
	else if (y == 3) d = c;
	else {
        if (y == 0) y = 124;
        for (int i = 4; i <= y; i++) {
            d = (a + b + c) % 10;
            a = b; b = c; c = d;
        }
    } cout << nr << "\n" << d << "\n";
    return 0;
}