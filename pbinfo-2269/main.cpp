#include <bits/stdc++.h>
using namespace std;
ifstream in("maximpar.in");
ofstream out("maximpar.out");
int main() {
    int n, val = 0, maxim = 0;
    in >> n;
    int multime[201];
    for (int i = 0 ; i < n; ++i) {
        in >> multime[i];
        if (multime[i] % 2 == 0 && multime[i] > maxim)
        maxim = multime[i];
    }
    for (int i = 0 ; i < n; ++i) {
        if (multime[i] == maxim)
        val++;
    }
    if (val == 0) out << -1;
    else out << maxim << " " << val;
    return 0;
}