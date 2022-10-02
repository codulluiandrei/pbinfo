#include <iostream>
using namespace std;
int pre(int n) {
    int ultima = n % 10, rez = 0, p = 1;
    n = n / 10;
    while (n > 0) {
        if (n % 10 != ultima) {
            rez = rez + (n % 10) * p;
            p = p * 10;
        } n = n / 10;
    } return rez;
}
int main() {
    int n, S = 0; cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        S = S + pre(temp);
    } cout << S;
    return 0;
}