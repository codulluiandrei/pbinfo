#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, nraparitii = 0, ultimacif;
    cin >> n; ultimacif = n % 10;
    do {
        if (ultimacif == n % 10)
            nraparitii++;
        n = n / 10;
    } while(n);
    cout << nraparitii;
    return 0;
}