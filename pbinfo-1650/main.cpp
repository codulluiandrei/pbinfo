#include <iostream>
using namespace std;
int n, k, temp, copie, i;
int main() {
    cin >> n;
    copie = n;
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> temp;
        n = n + temp;
    } if (n == copie) cout << "DA";
    else cout << "NU";
    return 0;
}