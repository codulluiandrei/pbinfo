#include <iostream>
using namespace std;
int main() {
    int n, a = 0, b = 0, c = 0, d = 0, e = 1, f = 0; cin >> n;
    int temp = n, temp2 = n, nrcif = 0, cifn[10001];
    int cif1 = temp % 10;
    while (temp != 0) {
        nrcif++;
        temp = temp / 10;
    }
    while (temp2 >= 10) {
        temp2 = temp2 / 10;
    } 
    for (int i = 0; i < nrcif; i++) {
        cifn[i] = n % 10;
        n = n / 10;
    }
    for (int i = 0; i < nrcif; i++) {
        a = cifn[i] * cifn[i] + a;
    } cout << a << " ";
    for (int i = 0; i < nrcif; i++) {
        if (cifn[i] % 2 != 0) {
            b = cifn[i] + b;
        }
    } cout << b << " ";
    for (int i = 0; i < nrcif; i++) {
        if (cifn[i] % 3 == 0) {
            c = cifn[i] + c;
        }
    } cout << c << " ";
    for (int i = 0; i < nrcif; i++) {
        if (cifn[i] > 5) {
            d++;
        }
    } cout << d << " ";
    for (int i = 0; i < nrcif; i++) {
        if (cifn[i] > 0) {
            e = cifn[i] * e;
        }
    } cout << e << " ";
    f = cif1 + temp2; cout << f;
    return 0;
}