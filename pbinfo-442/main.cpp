#include <iostream>
using namespace std;
int main() {
    int n, a, b, var = 1;
    cin >> n;
    int temp = n, nrcif = 0;
    while (temp != 0) {
        nrcif++;
        temp = temp / 10;
    } if (nrcif % 2 == 0) {
        while (nrcif / 2 > 0) {
            var = var * 10;
            nrcif = nrcif - 2;
        } a = n % var;
        b = n / var;
    } else if (nrcif % 2 == 1) {
            while (nrcif / 2 > 0) {
                var = var * 10;
                nrcif = nrcif - 2;
            } a = n % var;
            b = n / var / 10;
    } if (a > b) cout << a - b;
    else cout << b - a;
    return 0;
}
