#include <iostream>
using namespace std;
int main() {
    int n, contor = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        int p = 1, q = 0, a = 0, b;
        bool adv = false;
        if (temp == 0) adv = true;
        while (temp) {
            if (temp % 2 == 0) {
                a = a + temp % 10 * p;
                p = p * 10;
                adv = true;
            } temp = temp / 10;
        } b = a;
        while (b) {
            q = q * 10 + b % 10;
            b = b / 10;
        } if (a == q && adv) contor++;
    } cout << contor;
    return 0;
}