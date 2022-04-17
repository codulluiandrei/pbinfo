#include <iostream>
using namespace std;
int main() {
    int n, temp, a, b, nrcif = 0, val = 1;
    cin >> n; temp = n;
    while (n != 0) {
        n = n / 10;
        nrcif++;
    } for (int i = 1; i <= nrcif / 2; i++) val = val * 10;
    if (nrcif % 2 == 0) {
        b = temp % val;
        a = temp / val;
    } else if (nrcif % 2 == 1) {
        b = temp % val;
        a = temp / (val * 10);
    } while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    } cout << a;
    return 0;
}