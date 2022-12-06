#include <iostream>
using namespace std;
int n, doi = 0, cinci = 0, rez = 1;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int temp = i;
        while (temp % 5 == 0) {
                cinci++;
                temp = temp / 5;
        } while (temp % 2 == 0) {
                doi++;
                temp = temp / 2;
        } rez = (rez * temp) % 10;
    } int var = doi - cinci;
    for (int i = 1; i <= var; ++i)
        rez = (2 * rez) % 10;
    cout << rez;
    return 0;
}