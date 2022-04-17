#include <iostream>
using namespace std;
int main() {
    int n, nr = 0, maxim, temp, var;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> var;
        maxim = 0;
        while (var > 0) {
            temp = var % 10;
            if (temp > maxim) maxim = temp;
            var = var / 10;
        } if (maxim % 2 == 1) nr++;
    } cout << nr;
    return 0;
}