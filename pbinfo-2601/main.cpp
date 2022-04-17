#include <bits/stdc++.h>
using namespace std;
int cif1, cif2, cif3, nr;
int main () {
    cin >> nr;
    cif1 = nr % 10;
    cif2 = nr / 10 % 10;
    cif3 = nr / 100 % 10;
    cout << cif1 * cif1 + cif2 * cif2 + cif3 * cif3;
    return 0;
}