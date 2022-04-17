#include <iostream>
using namespace std;
int main() {
    int a, b, nra, nrb;
    cin >> a >> b;
    nra = a, nrb = b;
    while (nrb != 0) {
        int temp = nra % nrb;
        nra = nrb;
        nrb = temp;
    } cout << nra << " " << (long long) a / nra * b;
    return 0;
}