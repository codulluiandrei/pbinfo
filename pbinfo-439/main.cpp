#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int n, p = 1, s = 0;
    cin >> n;
    while (pow(5, p) <= n) {
        s = s + n / (pow(5, p));
        p++;
    } cout << s;
    return 0;
}