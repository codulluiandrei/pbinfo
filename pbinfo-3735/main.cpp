#include <bits/stdc++.h>
using namespace std;
ifstream in("concurs.in");
ofstream out("concurs.out");
long long C, n, temp, punctaj, maxim, a, b, c, nr, L;
int main () {
    in >> C >> n;
    for (int i = 1; i <= n; i++) {
        in >> L >> temp;
        punctaj = 0;
        while (temp != 0) {
            if (temp % 10 != 0) {
                punctaj = punctaj + temp % 10;
                temp = temp / 10;
            } else {
                punctaj = punctaj + temp % 100;
                temp = temp / 100;
            }
        } if (C == 1) {
            if (punctaj > maxim) {
                maxim = punctaj;
                nr = 1;
            } else if (punctaj == maxim) nr++;
        } else {
            if (L == 1) a = a + punctaj;
            if (L == 2) b = b + punctaj;
            if (L == 3) c = c + punctaj;
        }
    } if (C == 1) out << maxim << " " << nr << "\n";
    else if (a == b && a == c && a == 0) out << "FARA CAMPION\n";
        else {
            if (a == b && a > c) out << "1 2 " << b << "\n";
            else if (a == c && a > b) out << "1 3 " << c << "\n";
                else if (c == b && c > a) out << "2 3 " << c << "\n";
                    else if (a > b && a > c) out << "1 " << a << "\n";
                        else if (b > a && b > c) out << "2 " << b << "\n";
                            else if (c > a && c > b) out << "3 " << c << "\n";
                                else { out << "1 2 3 " << c << "\n"; }
        } return 0;
}
