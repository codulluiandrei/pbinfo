#include <iostream>
using namespace std;
int main() {
    int cif, n, a = 0, b = 0, c = 0, d = 0, e = 1, f;
    cin >> n;
    f = n % 10;
    while (n > 0) {
        cif = n % 10;
        n = n / 10;
        a = a + cif * cif;
        if (cif % 2 == 1)
            b = b + cif;
        if (cif % 3 == 0)
            c = c + cif;
        if (cif > 5)
            d++;
        if (cif != 0)
            e = e * cif;
        if (n < 10) 
            f = f + n;
    } cout << a << " " << b << " " << c << " " << d << " " << e << " " << f;
    return 0;
}