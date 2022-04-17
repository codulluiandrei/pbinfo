#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a;
    cin >> n;
    a = sqrt(n);
    if (a * (a + 1) == n) cout << a << " " << a + 1;
    else cout << "NU EXISTA";
    return 0;
}
