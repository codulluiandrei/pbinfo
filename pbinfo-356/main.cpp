#include <iostream>
using namespace std;
int main() {
    int n, a, b, maxima, maximb, maxim;
    cin >> n >> maxima >> maximb;
    if (maxima - maximb > 0) maxim = maxima - maximb;
    else maxim = maximb - maxima;
    for (int i = 2; i <= n; ++i) {
        cin >> a >> b;
        int var = a > b ? a - b : b - a;
        if (var > maxim) {
            maxim = var; maxima = a; maximb = b;
        }
    } cout << maxima << " " << maximb;
    return 0;
}