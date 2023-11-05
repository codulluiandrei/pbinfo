#include <iostream>
using namespace std;
int main() {
    long long int n, m, oglinda = 0;
    cin >> n;
    m = n;
    while (n > 0) {
        oglinda = oglinda * 10 + n % 10;
        n = n / 10;
    } n = m + oglinda;
    m = 0;
    while (n > 0) {
        if (n % 10 != 9) m++;
        n = n / 10;
    } if (m == 0) cout << "DA";
    else cout << "NU";
    return 0;
}