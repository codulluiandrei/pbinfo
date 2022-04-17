#include <iostream>
using namespace std;
int n, v[501];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int ok = 0;
    for (int i = 1; i <= n; i++)
        if (v[i] % 2 == 1) ok = 1;
    if (ok) cout << "DA";
    else cout << "NU";
    return 0;
}