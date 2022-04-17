#include <iostream>
using namespace std;
int main () {
    long long int n; cin >> n;
    while (n != 0) {
        if (n >= 10 && n <= 99)
            cout << (n / 10) * (n % 10);
        n = n / 10;
    } return 0;
}