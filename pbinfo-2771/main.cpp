#include <iostream>
using namespace std;
unsigned long long n, m, rez;
int main() {
    cin >> n >> m;
    cout << min(n, m) << " ";
    if (n == m) {
        cout << 1;
        return 0;
    } while (n > 1 || m > 1) {
        if (n > m) {
            rez = rez + n / m;
            n = n - m * (n / m);
        } else {
            rez = rez + m / n;
            m = m - n * (m / n);
        }
    } cout << rez;
    return 0;
}