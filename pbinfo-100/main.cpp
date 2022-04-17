#include <bits/stdc++.h>
using namespace std;

ifstream in("nrapprime.in");
ofstream out("nrapprime.out");

int verifprim(int n) {
    if (n < 2) return 0;
    if (n % 2 == 0 && n > 2) return 0;
    for (int d = 3; d * d <= n; d = d + 2)
        if (n % d == 0)
            return 0;
    return 1;
}

int main() {
    int n, v[101], nrprime = 0; in >> n;
    for (int i = 0; i < n; i++) in >> v[i];
    for (int i = 0; i < n; i++)
        if (verifprim(v[i]))
            nrprime++;
    out << nrprime << endl;
    return 0;
}