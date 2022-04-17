#include <iostream>
using namespace std;
int main() {
    unsigned n, maxim = 10;
    cin >> n;
    if (n == 0) maxim = 0;
    while (n != 0) {
        if (maxim == 10) {
            if (n % 2 == 0) maxim = n % 10;
        }
        else {
            if (n % 10 > maxim && n % 2 == 0) maxim = n % 10;
        } n = n / 10;
    } cout << maxim;
	return 0;
}