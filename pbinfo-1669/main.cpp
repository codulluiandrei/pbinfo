#include <iostream>
using namespace std;
int prim(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i < n; i++)
        if (n % i == 0) return 0;
    return 1;
}
int oglindit(int n) {
    int ogl = 0;
    while (n) {
        ogl = ogl * 10 + n % 10;
        n = n / 10;
    } return ogl;
}
int palindrom(int n) {
    if (n == oglindit(n)) return 1;
    return 0;
}
int norocos(int n) {
    if (n % 2 == 1) return 1;
    return 0;
}
int main() {
    int n, temp, var = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        if (palindrom(temp) && norocos(temp) && prim(temp)) var++;
    } cout << var;
    return 0;
}