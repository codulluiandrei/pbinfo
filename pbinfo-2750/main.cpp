#include <iostream>
using namespace std;
int main() {
    long long int a, b, cifa, cifb, minim = 100, maxim = -1, copie;
    cin >> a >> b;
    while (a > 0) {
        copie = b;
        cifa = a % 10;
        while (copie > 0) {
            cifb = copie % 10;
            if (cifa * 10 + cifb > 9 && cifa * 10 + cifb > maxim) maxim = cifa * 10 + cifb;
            if (cifb * 10 + cifa > 9 && cifb * 10 + cifa > maxim) maxim = cifb * 10 + cifa;
            if (cifa * 10 + cifb > 9 && cifa * 10 + cifb < minim) minim = cifa * 10 + cifb;
            if (cifb * 10 + cifa > 9 && cifb * 10 + cifa < minim) minim = cifb * 10 + cifa;
            copie = copie / 10;
        } a = a / 10;
    } cout << minim << " " << maxim;
    return 0;
}