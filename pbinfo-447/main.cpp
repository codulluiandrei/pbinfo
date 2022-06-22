#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, cif1, cif2, cif3;
    cin >> n;
    cif1 = n / 100;
    cif2 = (n % 100) / 10;
    cif3 = (n % 100) % 10;
    if ((cif1 < cif2 && cif2 < cif3) || (cif3 < cif2 && cif2 < cif1)) cout << cif2;
    else if ((cif2 < cif1 && cif1 < cif3) || (cif3 < cif1 && cif1 < cif2)) cout << cif1;
    else cout << cif3;
    return 0;
}