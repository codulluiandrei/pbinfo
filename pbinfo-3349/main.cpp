#include <iostream>
using namespace std;
int main() {
    int b, n, p;
    cin >> b >> n >> p;
    int M = 1;
    while (p != 0) {
        M = M * 10; 
        p--;
    } int R = 1;
    while (n != 0) {
        if (n % 2 == 1)
            R = 1LL * R * b % M;
        b = 1LL * b * b % M;
        n = n / 2;
    } cout << R;
    return 0;
}