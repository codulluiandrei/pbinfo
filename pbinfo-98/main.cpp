#include <bits/stdc++.h>
using namespace std;

ifstream in("maxim4.in");
ofstream out("maxim4.out");

int main() {
    int n, v, maxim = -1, nrmaxim = 0; in >> n;
    for (int i = 0; i < n; --n) {
        in >> v;
        if (v > maxim) maxim = v, nrmaxim = 1;
        else if (v == maxim) nrmaxim++;
    } out << maxim << " " << nrmaxim;
    return 0;
}