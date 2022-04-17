#include <iostream>
using namespace std;
int main() {
    int n, x, y;
    cin >> x >> y;
    n = y / x;
    if (y % x != 0)
        n = n + 1;
    cout << n;
    return 0;
}