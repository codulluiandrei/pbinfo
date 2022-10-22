#include <bits/stdc++.h>
using namespace std;
long long int n, nrcif = 0, rez;
long long int maxim = -1, ptemp, p = 100;
int st, dr;
int main() {
    cin >> n; st = n / p;
    while (st > 0) {
        st = n / p;
        dr = n % (p / 10);
        ptemp = st * dr;
        if (ptemp > maxim)
            maxim = ptemp;
        p = p * 10;
    } cout << maxim << " ";
    long long int copie = n;
    p = 9;
    while (copie != 0) {
        nrcif++;
        copie = copie / 10;
    } for (int i = 1; i < nrcif; i++) {
        rez = rez + i * p;
        p = p * 10;
    } p = p / 9;
    rez = rez + (n - p + 1) * nrcif + 1;
    cout << rez;
    return 0;
}