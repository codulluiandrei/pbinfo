#include <iostream>
using namespace std;
int main() {
    int n, x, y, counter = 0, minim = 100000000;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        if (abs(x - y) < minim) {
            minim = abs(x - y);
            counter = i;
        } else if (abs(x - y) == minim) 
            counter = i;
    } cout << counter;
    return 0;
}