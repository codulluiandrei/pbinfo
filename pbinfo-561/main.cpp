#include <iostream>
using namespace std;
int main () {
    int S, N, temp, var = 0, maxim = 0, x, y;
    cin >> S >> N;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        var++;
        if (S / temp > maxim) {
            maxim = S / temp;
            x = S / temp;
            y = var;
        }
    } cout << x << " " << y;
    return 0;
}