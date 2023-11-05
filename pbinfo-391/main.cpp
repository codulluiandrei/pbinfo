#include <iostream>
using namespace std;
int main() {
    int n, a, b, p = 0, q = 1;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a >> b;
        p = a * q + b * p;
        q = b * q;
        int x = p, y = q, r;
        while (x % y != 0) {
            r = x % y;
            x = y;
            y = r;
        } p = p / y, q = q / y;
    } cout << p << " " << q; 
    return 0;
}