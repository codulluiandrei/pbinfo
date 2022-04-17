#include <iostream>
using namespace std;
int nrdiv(int n) {
    int temp = 0;
    for (int i = 1 ; i * i <= n; i++) {
        if (i * i == n) temp--;
        if (n % i == 0) temp = temp + 2;
    } return temp;
}
int main() {
    int n, maxim = 0, minim = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (nrdiv(i) > maxim) maxim = nrdiv(i), minim = i;
    } cout << minim;
}