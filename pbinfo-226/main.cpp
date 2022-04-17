#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == a || j == b) cout << 0 << " ";
            if (i < a && j < b) cout << 1 << " ";
            if (i > a && j < b) cout << 3 << " ";
            if (i < a && j > b) cout << 2 << " ";
            if (i > a && j > b) cout << 4 << " " ;
        } cout << endl;
    } return 0;
}