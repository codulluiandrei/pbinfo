#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, z, h, x, y, n;
    cin >> x >> y >> n;
    a = n / (x * y);
    n = n - a * x * y;
    z = n / y;
    h = n - z * y;
    cout << a << endl;
    cout << z << endl;
    cout << h << endl;
    return 0;
}