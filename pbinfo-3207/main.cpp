#include <iostream>
using namespace std;
int main() {
    long double r1, x1, y1, r2, x2, y2;
    cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2;
    if (r1 == r2 && x1 == x2 && y1 == y2)
        cout << "infinit";
    else if ((x1 - x2) * (x1 - x2) +
             (y1 - y2) * (y1 - y2) == 
             (r1 + r2) * (r1 + r2) ||
             (x1 - x2) * (x1 - x2) + 
             (y1 - y2) * (y1 - y2) ==
             (r1 - r2) * (r1 - r2)) cout << 1;
    else if ((x1 - x2) * (x1 - x2) +
             (y1 - y2) * (y1 - y2) > 
             (r1 + r2) * (r1 + r2) ||
             (r1 - r2) * (r1 - r2) >
             (x1 - x2) * (x1 - x2) +
             (y1 - y2) * (y1 - y2) ||
             (x1 - x2) * (x1 - x2) + 
             (y1 - y2) * (y1 - y2) == 0) cout << 0;
    else cout << 2;
    return 0;
}