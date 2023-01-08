#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n, maxim = 0, d = 2;
    cin >> n;
    while (n > 1) {
        int contor = 0;
        while (n % d == 0) 
            n = n / d, contor++;
        if (contor != 0)
            maxim = d;
        d++;
        if (d * d > n)
            d = n;
    } cout << maxim;
    return 0;
}