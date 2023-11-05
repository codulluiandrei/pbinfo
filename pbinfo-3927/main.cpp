#include <iostream>
using namespace std;
int main() {
    long long int m, n, p = 1, maxim = 0;
    cin >> n;
    while (p <= n) {
        m = n / p / 10 * p + n % p;
        if (m > maxim) maxim = m;
        p = p * 10;
    } cout << maxim;
    return 0;
}