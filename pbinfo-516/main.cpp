#include <iostream>
using namespace std;
int main() {
    int v[10001], poz_min = 0, poz_max = 0, n, S = 0;
    bool adv = false;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] % 2 == 1 && adv == false) {
            poz_min = i;
            adv = true;
        } else if (v[i] % 2 == 1) poz_max = i;
    } for (int i = 1; i <= n; ++i) {
        if (i >= poz_min && i <= poz_max)
            S = S + v[i];
    } cout << S;
    return 0;
}