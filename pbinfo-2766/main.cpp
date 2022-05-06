#include <iostream>
using namespace std;
int main() {
    int r1, r2, g1, g2, b1, b2, n;
    cin >> r1 >> g1 >> b1 >> r2 >> g2 >> b2 >> n;
    int dr, dg, db;
    dr = r2 - r1;
    dg = g2 - g1;
    db = b2 - b1;
    cout << r1 << ", " << g1 << ", " << b1 << "\n";
    --n;
    for (int i = 1; i <= n; ++i)
        cout << (int)(r1 + dr * i / (double) n) << ", " << (int)(g1 + dg * i / (double) n) << ", " << (int)(b1 + db * i / (double) n) << "\n";
    return 0;
}