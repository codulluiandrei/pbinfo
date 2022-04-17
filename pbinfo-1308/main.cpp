#include <bits/stdc++.h>
using namespace std;
int main () {
    int m, n;
    int a, b, c, d;
    cin >> m >> n;
    a = m / 10;
    b = m % 10;
    c = n / 10;
    d = n % 10;
    if (a == b || a == c || a == d || b == c || b == d) cout << "da";
    else cout << "nu";
    return 0;
}