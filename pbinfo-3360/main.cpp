#include <iostream>
using namespace std;
int main() {
    int n, a, b, amax = 1000000000, bmax = 1000000000;
    cin >> n >> a;
    for (int i = 2; i <= n; i++) {
        cin >> b;
        int copiea = a, copieb = b, d = 2, contora = 0, contorb = 0;
        while (copiea > 1) {
            if (copiea % d == 0) {
                contora++;
                while (copiea % d == 0)
                    copiea = copiea / d;
            } d++;
            if (d * d > copiea) d = copiea;
        } d = 2;
        while (copieb > 1) {
            if (copieb % d == 0) {
                contorb++;
                while (copieb % d == 0)
                    copieb = copieb / d;
            } d++;
            if (d * d > copieb) d = copieb;
        } if (contora == contorb) {
            if (a + b < amax + bmax)
                amax = a, bmax = b;
        } a = b;
    } if (amax < 1000000000) cout << amax << " " << bmax;
    else cout << "NU EXISTA";
    return 0;
}
