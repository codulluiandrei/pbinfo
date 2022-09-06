#include <iostream>
using namespace std;
int main() {
    int n, nn, maxim = -1, temp = 0;
    cin >> n; nn = n;
    while (n > 0) {
        temp++;
        int var = 0, ind = 1, i = 1, copie = nn;
        while (copie != 0) {
            if (i != temp) {
                var = var + ind * (copie % 10);
                ind = ind * 10;
            } i++;
            copie = copie / 10;
        } if (var > maxim)
            maxim = var;
        n = n / 10;
    } cout << maxim;
    return 0;
}