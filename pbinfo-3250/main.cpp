#include <iostream>
using namespace std;
int main() {
    int a, b;
    long long int S = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        int copie = i;
        int simp = 0, spare = 0;
        while (copie > 0) {
            if (copie % 2 == 0) spare = spare + copie % 10;
            else simp = simp + copie % 10;
            copie = copie / 10;
        } if (simp == spare) S = S + i;
    } cout << S;
    return 0;
}