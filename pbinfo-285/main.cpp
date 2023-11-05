#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int k;
    cin >> k;
    for (int x = 1; x * x <= k / 2; ++x) {
        int z = k - x * x;
        int y = sqrt(z);
        if (z == y * y)
            cout << x << " " << y << "\n";
    } return 0;
}