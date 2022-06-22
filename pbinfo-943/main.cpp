#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, S = 0, x;
    cin >> n;
    n = n % 100;
    for (int i = 1; i <= n; i++) {
        x = i % 10;
        S = (S + x * x * x * x) % 10;
    } cout << S;
    return 0;
}