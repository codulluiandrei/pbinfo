#include <bits/stdc++.h>
using namespace std;
ifstream in("cifra2.in");
ofstream out("cifra2.out");
#define cin in
#define cout out
int n;
int minimcif(int n) {
    int minim = 10;
    while (n > 0) {
        if (n % 10 < minim)
            minim = n % 10;
        n = n / 10;
    } return minim;
}
int modifrec(int n) {
    int v = 0, minim = minimcif(n), p = 1;
    while (n > 0) {
        if (minim != n % 10) {
            v = v + n % 10 * p;
            p = p * 10;
        } n = n / 10;
    } n = v, v = 0, p = 1;
    while (n > 0) {
        v = v + (n % 10 - minim) * p;
        p = p * 10;
        n = n / 10;
    } return v;
}
int main() {
    cin >> n;
    cout << minimcif(n) << "\n";
    cout << modifrec(n) << "\n";
    while (modifrec(n) > 10)
        n = modifrec(n);
    cout << modifrec(n) << "\n";
    return 0;
}