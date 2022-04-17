#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    unsigned long long S = 0;
    for (int i = 1; i <= n; i++) {
        int temp, oglinda = 0; cin >> temp;
        while (temp != 0) {
            oglinda = oglinda * 10 + temp % 10;
            temp = temp / 10;
        } for (int j = 1; j * j <= oglinda; j++) {
            if (oglinda % j == 0) {
            	S = S + oglinda / j;
                S = S + j;
            } if (j * j == oglinda) S = S - j;
        }
    } cout << S;
    return 0;
}