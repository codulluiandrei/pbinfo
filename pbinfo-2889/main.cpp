#include <bits/stdc++.h>
using namespace std;
int main() {
    double r; cin >> r;
    double nrpi = 3.14159265359;
    cout << fixed << setprecision(10) << (double) nrpi * (r * r) << " ";
    cout << fixed << setprecision(10) << (double) nrpi * (2 * r);
    return 0;
}