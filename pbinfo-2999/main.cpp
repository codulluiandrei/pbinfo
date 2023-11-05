#include <iostream>
using namespace std;
int n, k, r, i = 1;
int main() {
    cin >> n >> k >> r;
    cout << n / 2 << "\n";
    int p = ((k - 1) * k) / 2;
    int u = p + k - 1;
    int p1 = ((r - 1) * r) / 2;
    int u1 = p1 + r - 1;
    cout << (((u1 + 1) * u1) / 2 - (p1 * (p1 - 1)) / 2 + ((u + 1) * u) / 2 - (p * (p - 1)) / 2) / (k + r) << "\n";
    while (i <= r) {
        cout << p1 << " "; i++;
        if (i <= r) cout << p1 + 1 << " ";
        i++; if (i <= r) cout << u1 << " ";
        i++; p1 = p1 + 2; u1--;
    } return 0;
}