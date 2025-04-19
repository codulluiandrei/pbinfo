#include <iostream>
#include <math.h>
using namespace std;
int main() {
    long long int n, P = 1, v = 1;
    cin >> n;
    while (n > 0) {
        if (v % 2 == 0) {
            n--;
            P = P * v;
        } v++;
    } cout << P;
    return 0;
}