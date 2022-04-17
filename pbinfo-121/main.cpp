#include <iostream>
using namespace std;
int main () {
    long long n, maxim = 0, ap = 0, temp;
    cin >> n; temp = n;
    if (n == 0) cout << 0 << " " << 1;
    else {
    while (n != 0) {
        if ((n % 10) > maxim) {
            maxim = n % 10;
        } n = n / 10;
    } while (temp != 0) {
        if ((temp % 10) == maxim) ap++;
        temp = temp / 10;
    } cout << maxim << " "<< ap; }
    return 0;
}