#include <iostream>
using namespace std;
int main() {
    int n, x, minim = 9, maxim = 0;
    cin >> n;
    for (int i = 1; i <=n; i++) {
        cin >> x;
        int y = x;
        while (y > 9) y = y / 10;
        if (y < minim) {
            minim = y;
            maxim = x;
        } else if (y == minim) if(x > maxim) maxim = x;
    } cout << maxim;
    return 0;
}
