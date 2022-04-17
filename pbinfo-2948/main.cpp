#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main() {
    double n, x, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        s = s + x * x;
    } s = s / n;
    s = sqrt(s);
    cout << fixed << setprecision(2) << s;
}