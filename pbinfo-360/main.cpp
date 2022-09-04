#include <iostream>
using namespace std;
int main() {
    long long int a, b, temp = 0, ind = 1;
    cin >> a >> b;
    while (a > 0) {
        if (a % 10 != b) {
            temp = temp + a % 10 * ind;
            ind = ind * 10;
        } a = a / 10;
    } if (ind != 1) cout << temp;
    else cout << -1;
}