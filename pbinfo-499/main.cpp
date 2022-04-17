#include <bits/stdc++.h>
using namespace std;

int numarare5(int n) {
    int S = 0;
    while (n) {
        S = S + n % 10;
        n = n / 10;
    } return S;
}

int main() {
    int n, C = 0, vec[205];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> vec[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (numarare5(vec[i]) == numarare5(vec[j])) {
                C++;
            }
        }
    } cout << C;
    return 0;
}