#include <bits/stdc++.h>
using namespace std;
int main() {
    int nra, nrb;
    cin >> nra >> nrb;
    int P = 2 * nra + 2 * nrb;
    int A = nra * nrb;
    int D = nra * nra + nrb * nrb;
    cout << P << " " << A << " " << D;
}