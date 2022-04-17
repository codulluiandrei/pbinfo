#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, temp0, temp1, temp2; cin >> n;
    temp0 = 1;
    temp1 = 1;
    if (n == 1) cout << 1;
    else {
        cout << 1 << " " << 1 << " ";
        n = n - 2;
        while (n > 0) {
            temp2 = temp0 + temp1;
            temp0 = temp1;
            temp1 = temp2;
            cout << temp2 << ' ';
            n--;
        }
    } return 0;
}