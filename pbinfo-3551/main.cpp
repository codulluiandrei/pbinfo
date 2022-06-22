#include <bits/stdc++.h>
using namespace std;
int main() {
    int cat1, cat2, ip;
    cin >> cat1 >> cat2 >> ip;
    cat1 = cat1 * cat2;
    double inal = (double) cat1 / ip;
    inal = (int) (inal * 100) / 100.;
    cout << fixed << setprecision(2) << inal;
    return 0;
}