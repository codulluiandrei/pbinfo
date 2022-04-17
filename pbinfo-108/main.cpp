#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, nraparitii = 0, primacif;
    cin >> n; primacif = n;
    while (primacif > 9) primacif = primacif / 10;
    do {
        if (primacif == n % 10) nraparitii++;
        n = n / 10;
    } while(n);
    cout << nraparitii;
    return 0;
}