#include <iostream>
using namespace std;
int n, v[101];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    bool adv = true;
    for (int i = 1; i < n; i++) {
        if (v[i] % v[n] != 0)
            adv = false;
    } if (adv) cout << "DA";
    else cout << "NU";
    return 0;
}