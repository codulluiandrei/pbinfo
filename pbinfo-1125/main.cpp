#include <iostream>
using namespace std;
const unsigned long long lim = -1;
int n, m;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        unsigned long long nr = 0;
        bool adv = true;
        for (int a, b, j = 0; j < m; ++j) {
            cin >> a >> b;
            if (adv == false) continue;
            unsigned long long rez = a;
            for (int k = 2; k <= b && adv; ++k) {
                if (!rez || !a || rez <= lim / a) rez = rez * a;
                else adv = false;
            } if (!b) rez = 1;
            if (adv == false) continue;
            if (nr <= lim - rez) nr = nr + rez;
            else adv = false;
        } if (adv == true) cout << nr << "\n";
        else cout << "Overflow!\n";
    } return 0;
}