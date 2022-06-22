#include <bits/stdc++.h>
using namespace std;
int sumacif(int a) {
    int suma = 0;
    while (a) suma = suma + a % 10, a = a / 10;
    return suma;
}
int main() {
    int nr1, nr2, nr3, maxim = 0;
    cin >> nr1 >> nr2 >> nr3;
    if(sumacif(nr1) > maxim)
        maxim = sumacif(nr1);
    if(sumacif(nr2) > maxim)
        maxim = sumacif(nr2);
    if(sumacif(nr3) > maxim)
        maxim = sumacif(nr3);
    if(sumacif(nr1) == maxim)
        cout << nr1 << " ";
    if(sumacif(nr2) == maxim)
        cout << nr2 << " ";
    if(sumacif(nr3) == maxim)
        cout << nr3 << " ";
    return 0;
}