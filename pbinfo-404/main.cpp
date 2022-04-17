#include <bits/stdc++.h>
using namespace std;
bool testprim(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}
int nrcifre(int n) {
    int s = 0;
    while(n) {
        n = n/10;
        s++;
    } return s;
}
int main() {
    int n, s = 0;
    long int nr;
    cin >> n;
    while(n) {
        cin >> nr;
        if (testprim(nr)) {
            s += nrcifre(nr);
        } n--;
    } cout << s;
    return 0;
}