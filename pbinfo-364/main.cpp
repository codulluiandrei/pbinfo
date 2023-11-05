#include <iostream>
using namespace std;
int main() {
    int n, x, cif = -1, maxim = -1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        int copie = x;
        while (copie > 9)
            copie = copie / 10;
        if (copie > cif)
            cif = copie, maxim = x;
        else if (copie == cif)
            if (x > maxim) maxim = x;
    } cout << maxim;
    return 0;
}