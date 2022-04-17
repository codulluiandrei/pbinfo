#include <bits/stdc++.h>
using namespace std;
int main() {
        int n, maxim = 0;
        cin >> n;
        while (n) {
            int temp = n % 10;
            if (temp > maxim) maxim = temp;
            n = n / 10;
        } cout << maxim;
    return 0;
}