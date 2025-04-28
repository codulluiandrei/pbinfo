#include <bits/stdc++.h>
using namespace std;
long double x;
long double cb(long double st, long double dr) {
    long double mij = (st + dr) / 2, val = exp(mij);
    if(abs(val - x) < 0.0000001) return mij;
    if(val < x) return cb(mij, dr);
    return cb(st, mij);
}
int main() {
    cin >> x;
    cout << fixed << setprecision(6) << (int)(cb(0, 22) * 1000000) / 1000000.0;
    return 0;
}