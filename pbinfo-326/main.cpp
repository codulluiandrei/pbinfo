#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, temp, pare = -10;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp % 2 == 0)
        pare = temp;
    } if (pare == -10) cout << "IMPOSIBIL";
    else cout << pare;
    return 0;
}