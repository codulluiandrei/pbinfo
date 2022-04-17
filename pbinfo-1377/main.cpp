#include <bits/stdc++.h>
using namespace std;
ifstream in("maxd.in");
ofstream out("maxd.out");
int nrdiv(int nr) {
        int divi = 1, p, d = 2;
        while (nr > 1) {
            p = 0;
            while(nr  %d == 0) {
                p++;
                nr = nr / d;
            } divi = divi * (p + 1);
            d++;
            if (d * d > nr) d = nr;
        } return divi;
}
int main() {
    int a, b, maxim = 0, minim, temp = 0;
    in >> a >> b;
    for (int i = a; i <= b; i++) {
        int nrdivi = nrdiv(i);
        if (nrdivi > maxim) {
            maxim = nrdivi;
            minim = i;
            temp = 1;
        } else if (nrdivi == maxim) temp++;
    } out << minim << " " << maxim << " " << temp;
    return 0;
}