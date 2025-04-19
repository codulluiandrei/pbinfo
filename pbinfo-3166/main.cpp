#include <iostream>
using namespace std;
int main() {
    float x;
    long long int t, y, i, rez = 0;
    cin >> x >> t >> y >> i;
    while (x > y) {
        rez = rez + t;
        x = x - x / i;
    } cout << rez;
    return 0;
}