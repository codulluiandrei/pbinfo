#include <iostream>
using namespace std;
int main() {
    int n, p = 0, u = 0, maxim = 0;
    float temp; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        if (temp > maxim) {
            p = i;
            maxim = temp;
        } if (temp == maxim) u = i;
    } cout << p << " " << u;
    return 0;
}
