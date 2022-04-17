#include <iostream>
using namespace std;
int main() {
    int n, r = 0;
    cin >> n;
    while (n > 0) {
        r = r * 100 + n % 100;
        n = n / 100;
    } while(r > 0) {
        n = n * 10 + r % 10;
        r = r / 10;
    } cout << n;
    return 0;
}