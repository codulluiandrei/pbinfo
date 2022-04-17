#include <iostream>
using namespace std;
int n, m, x, y, sv, se, ne, nv;
int main() {
    cin >> x >> y >> n >> m;
    ne = x + m - y;
    se = n - x + m - y + 1;
    sv = n - x + y;
    nv = x + y - 1;
    cout << max(max(max(ne, se), sv), nv);
    return 0;
}