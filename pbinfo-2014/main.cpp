#include <bits/stdc++.h>
using namespace std;

ifstream in("canguri.in");
ofstream out("canguri.out");

int main() {
    int nr1, nr2, nr3, pas1, pas2, pas3;
    in >> nr1 >> pas1;
    in >> nr2 >> pas2;
    in >> nr3 >> pas3;
    int pasmax = pas1, nrmax = nr1;
    if (pas2 > pasmax) pasmax = pas2, nrmax = nr2;
    if (pas3 > pasmax) pasmax = pas3, nrmax = nr3;
    out << nrmax << endl;
    if (800 % pasmax == 0) out << 800 / pasmax;
    else out << 800 / pasmax + 1;
    return 0;
}