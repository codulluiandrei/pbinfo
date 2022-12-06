#include <bits/stdc++.h>
using namespace std;
int c, n, S = 0, contor = 0, numere = 0;
int c1, c3, c5, c7, c9;
int prim(int a) {
    if (a < 2) return 0;
    if (a == 2) return 1;
    if (a % 2 == 0) return 0;
    for (int d = 3; d * d <= a; d = d + 2)
        if (a % d == 0)
            return 0;
    return 1;
}
int apar(int a, int c) {
    int contor = 0;
    while (a > 0) {
        if (a % 10 == c)
            contor++;
        a = a / 10;
    } return contor;
}
int func(int cif, int cift) {
    while (cift != 0) {
        int r = cif % cift;
        cif = cift;
        cift = r;
    } return cif;
}
int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        if (prim(temp))
            S = S + temp;
        contor = contor + apar(temp, c);
        if (temp % 2 == 1)
            if (temp % 10 == 1)
                c1++;
            else if (temp % 10 == 3)
                c3++;
            else if (temp % 10 == 5)
                c5++;
            else if (temp % 10 == 7)
                c7++;
            else
                c9++;
    } cout << S << "\n";
    cout << contor << "\n";
    int cif = c1, cift = c3;
    cif = func(cif, cift);
    cift = c5;
    cif = func(cif, cift);
    cift = c7;
    cif = func(cif, cift);
    cift = c9;
    cif = func(cif, cift);
    numere = c1 / cif + c3 / cif + c5 / cif + c7 / cif + c9 / cif;
    cout << numere;
    return 0;
}