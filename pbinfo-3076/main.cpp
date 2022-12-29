#include <iostream>
using namespace std;
int main() {
    long long int n, S = 0, contor = 0, rez;
    cin >> n;
    while (n > 0) {
        S = S + n % 10;
        n = n / 10;
        contor = contor * 10 + 1;
    } rez = S * contor;
    cout << rez;
    return 0;
}