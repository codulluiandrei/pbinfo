#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, cifre; cin >> n;
    cifre = n % 10 * 10 + n / 10;
    cout << cifre * cifre;
    return 0;
}