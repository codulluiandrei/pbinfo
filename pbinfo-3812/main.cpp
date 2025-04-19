#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double AB, BC, AC, p, A, hA, hB, hC;
    cin >> AB >> BC >> AC;
    if (AB + BC >= AC && AB + AC >= BC && BC + AC >= AB) {
        p = (AB + BC + AC) / 2;
        A = sqrt(p * (p - AB) * (p - BC) * (p - AC));
        hA = (2 * A) / BC;
        hB = (2 * A) / AC;
        hC = (2 * A) / AB;
        int h1 = hA * 100, h2 = hB * 100, h3 = hC * 100;
        cout << h1 / 100 << "." << h1 / 10 % 10 << h1 % 10 << " ";
        cout << h2 / 100 << "." << h2 / 10 % 10 << h2 % 10 << " ";
        cout << h3 / 100 << "." << h3 / 10 % 10 << h3 % 10;
    }
    else cout << "Imposibil";
    return 0;
}