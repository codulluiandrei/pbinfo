#include <iostream>
using namespace std;
int main() {
    long long int n, S = 0, maxim;
    cin >> n;
    maxim = n % 10;
    S = S + maxim;
    while (n != 0) {
        n = n / 10;
        int c = n % 10;
        if (c > maxim)
            maxim = c, S = S + c;
    } cout << S;
    return 0;
}