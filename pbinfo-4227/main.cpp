#include <iostream>
using namespace std;
int main() {
    int n, m, var = 0;
    cin >> n >> m;
    while (n > 0) {
        if (n % 10 + m % 10 > 9) var++;
        n = n / 10;
        m = m / 10;
    } if (var == 0) cout << "NU";
    else cout << "DA";
    return 0;
}