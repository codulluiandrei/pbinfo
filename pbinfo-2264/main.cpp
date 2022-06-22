#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, cif1, cif2;
    cin >> n;
    cif1 = (n % 10);
    cif2 = ((n / 10) % 10);
    cout << cif1 + cif2;
}