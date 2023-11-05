#include <fstream>
using namespace std;
ifstream in("grupapregatitoare.in");
ofstream out("grupapregatitoare.out");
long long int n, p, suma = 0, flag = 0, minim = 20000;
long long int secpar = 0, secimp = 0, lp = 0, li = 0;
long long int x, y, nr1, nr2, maxim, lungi, lungp;
int main() {
    in >> n >> p;
    for (int i = 1; i <= n; i++) {
        in >> x >> y;
        if (x > y) suma = suma + x;
        else suma = suma + y ;
        if (((x % p == 0) && (x >= y)) || ((y % p == 0) && (y >= x))) flag = 1;
        if ((x % p == 0) && (x < y) && (y - x < minim)) {
            minim = y - x;
            nr1 = x;
            nr2 = y;
        } if ((y % p == 0) && (y < x) && (x - y < minim)) {
            minim = x - y;
            nr1 = y;
            nr2 = x;
        } if ((x % 2 == 0 ) || (y % 2 == 0)) secpar++;
        else {
            if (lp == 0) { lungp = secpar; lp = 1; }
            if (secpar > maxim) maxim = secpar;
            secpar = 0;
        } if ((x % 2 == 1) || (y % 2 == 1)) secimp++;
        else {
            if (li == 0) { lungi = secimp; li = 1; }
            if (secimp > maxim) maxim = secimp;
            secimp = 0;
        }
    } if (secpar + lungp > maxim) maxim = secpar + lungp;
    if (secimp + lungi > maxim) maxim = secimp + lungi;
    if (flag == 1) out << suma;
    else out << suma - nr2 + nr1;
    out << "\n" << maxim;
    return 0;
}