#include <iostream>
using namespace std;
int main() {
    int n, a = 0, b = 0, pa = 1, pb = 1;
    cin >> n;
    while (n) {
        if (n % 2 == 0) {
            a = a + n % 10 * pa;
            pa = pa * 10;
        } else {
            b = b + n % 10 * pb;
            pb = pb * 10;
        } n = n / 10;
    } cout << abs(a - b);
    return 0;
}