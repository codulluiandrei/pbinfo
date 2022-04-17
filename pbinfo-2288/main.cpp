#include <iostream>
using namespace std;
int main() {
    int n, temp = 0, maxim = 0; cin >> n;
    while (n != 0) {
        if ((n % 10) % 2 == 1 && n % 10 > maxim) {
            maxim = n % 10;
            temp++;
        } n = n / 10;
    } if (temp == 0) cout << "nu exista";
    else cout << maxim;
    return 0;
}