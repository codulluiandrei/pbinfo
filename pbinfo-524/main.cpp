#include <iostream>
using namespace std;
int v[1001], n, maxim, poz_temp, inc, sf, j;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = 1; i <= n; i++) {
        for (j = n ; j >= i; j--)
            if (v[i] == v[j]) {
            poz_temp = j - i + 1;
            break;
        } if (poz_temp > maxim) {
            sf = j;
            inc = i;
            maxim = poz_temp;
        }
    } cout << inc << " " << sf;
    return 0;
}
