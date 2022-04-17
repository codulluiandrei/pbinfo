#include <iostream>
using namespace std;
int main() {
    int x, y, n, val, rez;
    cin >> n >> x >> y >> val;
    rez = (x - 1) * n + y;
    cout << rez << " ";
    x = val / n;
    y = val % n;
    if (y == 0) y = n;
    else x++;
    cout << x << " "  << y;
    return 0;
}