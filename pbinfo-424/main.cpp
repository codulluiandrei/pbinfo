#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x, y , a, b, c;
    cin >> x >> y >> n;
    cout << x << " " << y << " ";
    a = x, b = y;
    c = a + b;
    while (abs(c) <= n) {
        cout << c << " ";
        a = b;
        b = c;
        c = a + b;
   	} return 0;
}
