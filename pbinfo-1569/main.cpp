#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int i2 = 1; i2 <= i; i2++) {
            for (int i3 = 1; i3 <= i; i3++)
                cout << i;
            cout << endl;
        }
    } return 0;
}