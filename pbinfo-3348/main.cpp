#include <bits/stdc++.h>
using namespace std;
int v[101], poz;
int main() {
    int n; cin >> n;
    while (n != 0) {
        v[++poz] = n % 2;
        n = n / 2;
    } int temp = 1;
    for (int i = 1; i <= poz; i++) {
        if (v[i] == 1)
            cout << temp << " ";
        temp = temp * 2;
    } return 0;
}