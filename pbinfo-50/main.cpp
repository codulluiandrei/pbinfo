#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    long long S = 0;
    for (int i = 1; i <= n; i++) {
        long long temp = 1;
        for(long long i2 = 1; i2 <= i; i2++)
            temp = temp * i2;
        S = S + temp;
    } cout << "Rezultatul este " << S;
    return 0;
}