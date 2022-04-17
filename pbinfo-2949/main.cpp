#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double n, x, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        s = s + 1 / x;
    } s = n / s;
    cout << fixed << setprecision(2) << s;
}