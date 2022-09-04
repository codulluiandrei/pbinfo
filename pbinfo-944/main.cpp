#include <iostream>
using namespace std;
int main() {
    long long int n, rez = 0, i = 1;
    cin >> n;
    while (i <= n) {
        int temp = n / (i * 10) * i + n % i;
        if (temp != 0) {
            if (n % temp > rez)
                rez = n % temp;
        } i = i * 10;
    } cout << rez;
    return 0;
}