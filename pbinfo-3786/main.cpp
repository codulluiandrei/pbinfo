#include <fstream>
using namespace std;
ifstream in("toate.in");
ofstream out("toate.out");
int n, i, a, x, p, r, maxim = 0;
int main() {
    in >> n;
    for (i = 1; i <= n; i++) {
        in >> x; a = 0; p = 1;
        while (x != 0) {
            r = x % 10;
            if (r != 9) {
                a = a + r * p;
                p = p * 10;
            } x = x / 10;
        } if (a > maxim) maxim = a;
    } out << maxim;
    return 0;
}
