# include <iostream>
using namespace std;
int main() {
    int n, v, p;
    cin >> n;
    bool adv = true;
    int nrpv = 9 + 2 * 90 + 3 * 201;
    v = n / nrpv;
    int r = n % nrpv;
    if (r == 0) {
        p = 300;
    } else {
        v++;
        p = 0;
        if (r < 10) p = r;
        else {
            p = 9;
            r = r - 9;
            if (r <= 2 * 90) {
                if (r % 2 == 0) p = p + r / 2;
                else adv = false;
            } else {
                p = p + 90;
                r = r - 2 * 90;
                if (r % 3 == 0) p = p + r / 3;
                else adv = false;
            }
        }
    } if (adv != 0) cout << v << " " << p;
    else cout << "IMPOSIBIL";
    return 0;
}
