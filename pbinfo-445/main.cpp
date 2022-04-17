#include <iostream>
using namespace std;
int main () {
    int n, S = 0;
    cin >> n;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            S = S + n / i;
            S = S + i;
        } if (i * i == n) S = S - i;
    } if (S % n == 0) cout << "DA";
    else cout << "NU";
    return 0;
}
