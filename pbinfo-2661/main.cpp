#include <iostream>
#include <math.h>
using namespace std;
int main() {
    long long int a, nrcif = 0, ind = 1;
    cin >> a;
    long long int copie = a;
    while (copie > 0) {
        nrcif++;
        copie = copie / 10;
    } copie = 0;
    for (int i = 1; i < nrcif; i++)
        ind = ind * 10;
    while (a > 0) {
        copie = copie + a % 10 * ind;
        ind = ind / 10;
        a = a / 10;
    } for (int i = 0; i < nrcif; i++) {
        if (i != floor(nrcif / 2))
            cout << copie % 10;
        copie = copie / 10;
    } return 0;
}