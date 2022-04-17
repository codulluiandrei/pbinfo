#include <bits/stdc++.h>
using namespace std;

ifstream in("zmeu.in");
ofstream out("zmeu.out");

int main() {
    long long n, m, total, incaunul;
    in >> n >> m;
    incaunul = n / (2 * m);
    total = n % (2 * m);
    out << incaunul << endl << (2 * m) - total;
    return 0;
}