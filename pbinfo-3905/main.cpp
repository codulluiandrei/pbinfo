#include <iostream>
using namespace std;
int main() {
    int n, sc = 0, nc = 0, x = 0, f = 1;
    cin >> n;
    if (n == 0) nc =1;
    while (n > 0) {
        x = x * 10 + 1;
        nc++;
        f = f * nc;
        sc = sc + n % 10;
        n = n / 10;
    } f = f / nc;
    cout << 1LL * f * x * sc;
    return 0;
}
