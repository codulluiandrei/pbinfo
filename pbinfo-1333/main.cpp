#include <bits/stdc++.h>
using namespace std;
int main() {
    double B, b, l, inal, temp, diag;
    cin >> B >> b >> l;
    temp = (B - b) / 2;
    inal = sqrt(l * l - temp * temp);
    diag = sqrt((b + temp) * (b + temp) + inal * inal);
    cout << diag;
    return 0;
}