#include <iostream>
using namespace std;
int main() {
    int n, m = 1, d = 2;
    cin >> n;
    while (n > 1) {
        if (n % d == 0) {
            m = m * d;
            while (n % d == 0)
                n = n / d;
        } d++;
        if (d * d > n) d = n;
    } cout << m;
    return 0;
}