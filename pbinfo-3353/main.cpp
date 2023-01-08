#include <iostream>
using namespace std;
int n, m, S = 1, s = 1;
int main() {
    cin >> n >> m;
    int a = n , b = m;
    int d = 2;
    while (n > 1) {
        if (n % d == 0) {
            S = S * d;
            while (n % d == 0)
                n = n / d;
        } d++;
        if (d * d > n) d = n;
    } d = 2;
    while (m > 1) {
        if (m % d == 0) {
            s = s * d;
            while (m % d == 0)
                m = m / d;
        } d++;
        if (d * d > m) d = m;
    } if (S > s) cout << a;
    else if (S < s) cout << b;
    else if (a < b) cout << a;
    else cout << b;
    return 0;
}