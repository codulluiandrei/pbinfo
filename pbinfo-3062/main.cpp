#include <iostream>
using namespace std;
int main() {
    float x;
    int t, y, T = 0;
    cin >> x >> t >> y;
    while (x > y) {
        T = T + t;
        x = 3 * x / 4;
    } cout << T;
    return 0;
}