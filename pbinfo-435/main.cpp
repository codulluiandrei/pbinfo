#include <iostream>
using namespace std;
int main() {
    int n, m, d = 2;
    bool adv = true;
    cin >> n >> m;
    while (n > 1 && adv == true) {
        if (n % d == 0)
            if (m % d != 0)
            adv = false;
            else {
            	while (n % d == 0) n = n / d;
            	while (m % d == 0) m = m / d;
        } d++;
    } if (m != 1) adv = false;
    if (adv) cout << "DA";
    else cout << "NU";
    return 0;
}