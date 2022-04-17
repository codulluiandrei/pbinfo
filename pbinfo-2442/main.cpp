#include <bits/stdc++.h>
using namespace std;
ifstream in("cifre006.in");
ofstream out("cifre006.out");
int N, k, cif, ap, p = 1, N1, N2;
int main() {
    in >> N >> k;
    while (N) {
        cif = N % 10;
        if (cif == k) {
            ap++;
            N1 = N1 * 10 + cif;
        } else {
            N2 = N2 + cif * p;
            p = p * 10;
        } N = N / 10;
    } out << ap << '\n' << N1 * p + N2;
    return 0;
}