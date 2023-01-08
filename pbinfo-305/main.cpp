#include <iostream>
using namespace std;
int main() {
    int n, x, a, b, r;
    cin >> n;
    cin >> x;
    for (int i = 2; i <= n; ++i) {
        cin >> a;
        b = x;
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        } x = a;
    } cout << x;
    return 0;
}