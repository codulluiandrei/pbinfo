#include <iostream>
using namespace std;
bool verif(int x, int y) {
    int ux, uy;
    while (x > 0) {
        ux = x % 10;
        x = x / 10;
    } while (y > 0) { 
        uy = y % 10;
        y = y / 10;
    }
    if (ux == uy)
        return true;
    return false;
}
int main() {
    int x, y, counter = 0;
    while (cin >> x >> y && x != 0 && y != 0) {
        if (verif(x, y))
            counter++;
    } cout << counter;
    return 0;
}