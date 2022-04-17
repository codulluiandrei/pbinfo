#include <bits/stdc++.h>
using namespace std;
int main() {
    int temp = -1, n = 0;
    while (temp) {
        cin >> temp;
        if (temp > n)
            n = temp;
    }
    if (n == 0) cout << "NU EXISTA";
    else cout << n;
    return 0;
}