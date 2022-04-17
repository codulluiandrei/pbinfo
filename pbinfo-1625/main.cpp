#include <bits/stdc++.h>
using namespace std;
int main() {
    float delta, a, b, c, x1, x2;
    cin >> a >> b >> c;
    delta = b * b - 4 * a * c;
    if (delta > 0) {
        x1 = (- b - sqrt(delta)) / 2.0 / a;
        x2 = (- b + sqrt(delta)) / 2.0 / a;
        if (x1 > x2) cout << fixed << setprecision(2) << x1 << " " << x2;
        else cout << fixed << setprecision(2) << x2 << " " << x1;
    } else if (delta == 0)
        cout << fixed << setprecision(2) << "Radacina dubla " << (- b) / 2.0 / a;
        else cout <<"Nu are solutii reale";
    return 0;
}
