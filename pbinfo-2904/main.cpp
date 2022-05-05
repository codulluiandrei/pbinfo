#include <iostream>
#include <math.h>
using namespace std;
int main() {
    unsigned long long n, nr1, nr2;
    double temp;
    cin >> n;
    for (long long int i = 1; i <= n; i++) {
        nr1 = i * (i + 1) / 2;
        if (nr1 >= n) break;
        nr2 = n - nr1;
        temp = sqrt(8 * nr2 + 1);
        if((long long int) temp == temp) {
            cout << nr1 << " " << nr2;
            return 0;
        }
    } cout << "NU";
    return 0;
}