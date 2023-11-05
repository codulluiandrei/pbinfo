#include <iostream>
using namespace std;
int a, b, c;
int main() {
    int amax = -1, amin = 10;
    int bmax = -1, bmin = 10;
    cin >> a >> b;
    if (a == 0) amax = amin = 0;
    while (a) {
        c = a % 10;
        if (c > amax) amax = c;
        if (c < amin) amin = c;
        a = a / 10;
    } if (b == 0) bmax = bmin = 0;
    while (b) {
        c = b % 10;
        if (c > bmax) bmax = c;
        if (c < bmin) bmin = c;
        b = b / 10;
    } if (amax == bmin)
        cout << amax;
    else if (amin == bmax)
        cout << amin;
    else cout << "NU";
    return 0;
}