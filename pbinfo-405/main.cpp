#include <bits/stdc++.h>
using namespace std;
bool prim(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}
int sumcif(int n) {
    int S = 0;
    while (n != 0) {
       	S = S + n % 10;
        n = n / 10;
    } return S;
}
int main() {
    long long int n, S = 0, nr;
    cin >> n;
    while (n != 0) {
        cin >> nr;
        if (prim(nr)) {
            S = S + sumcif(nr);
        } n--;
    } cout << S;
    return 0;
}