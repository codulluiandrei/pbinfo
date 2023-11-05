#include <iostream>
#include <math.h>
using namespace std;
int main() {
    long long int n, contor = 0, x = 2;
    cin >> n;
    while (x <= n) {
        x = x * 2;
        contor++;
    } cout << contor;
    return 0;
}