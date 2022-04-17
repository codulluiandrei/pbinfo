#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

ifstream in ("formula1.in");
ofstream out ("formula1.out");

int main() {
    long long int n, k, C;
    in >> C >> k >> n;
    if (C == 1) {
        out << (2 * k - 1) * (2 * k - 1);
        return 0; 
    } long long S = ((2 * n - 1) * (2 * n) * (4 * n - 1) / 6 
    - 4 * (n - 1) * n * (2 * n - 1) / 6  - n ) / 2;
    long long maxim = sqrt(S * 2 + 1);
    if (maxim % 2 == 0) maxim--;
    out << maxim * maxim;
    return 0;
}