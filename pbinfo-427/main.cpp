#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, maxim = 0; cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        while (temp != 0) {
            if (temp % 10 > maxim)
                maxim = temp % 10;
            temp = temp / 10;
        }
    } cout << maxim + 1;
    return 0;
}