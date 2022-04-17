#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n, temp = 0;
    long long S = 0;
    cin >> n;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            temp++;
            S = S + i;
            if (i * i != n) {
                S = S + n / i;
                temp++;
            }
        }
    } cout << fixed << setprecision(2) << (float) S / temp;
    return 0;
}
