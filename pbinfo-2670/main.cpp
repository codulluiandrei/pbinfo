#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    for (int x = 1; x <= 10000; ++x) {
        int y1 = b * x;
        int y2 = a * x - b;
        if (y2 > 0 && y1 % y2 == 0) {
            int y = y1 / y2;
            if (x > y) break;
            cout << x << " " << y << "\n";
        }
    } return 0;
}