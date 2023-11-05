#include <iostream>
using namespace std;
int n, k, r;
int main() {
    cin >> n ;
    r = n % 3 ;
    k = 0 ;
    while (n != 0) {
        if ((n % 10) % 3 == r) k++;
        n = n / 10;
    } cout << k;
    return 0;
}