#include <iostream>
#include <math.h>
using namespace std;
int main() {
    long long int l, r, contor = 0;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (i % 2 == 0)
            contor++;
    } cout << contor * contor;
    return 0;
}