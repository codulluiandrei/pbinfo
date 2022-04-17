#include <iostream>
using namespace std;
int main() {
    int n, k, nrcif = 0, temp = 0;
    long long int P = 1;
    cin >> n >> k;
    while (n != 0) {
        if (n % 10 != k) P = P * (n % 10);
        else temp++;
        n = n / 10;
        nrcif++;
    } 
    if (nrcif > temp) cout << P;
    else cout << 0;
    return 0;
}