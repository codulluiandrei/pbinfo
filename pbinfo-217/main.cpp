#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i % 2 == 0) cout << j << " ";
            else if (i % 2 == 1) cout << i << " ";
        } cout << endl;
    } return 0;
}