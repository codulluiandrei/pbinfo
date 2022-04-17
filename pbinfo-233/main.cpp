#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, vec[500], temp1 = 1, temp2 = 0;
    cin >> n;
    for (int i = 1; i < 500; i++) vec[i] = i;
    for (int i = 1; i <= 2 * n; i++) {
        if (i % 2 == 1) {
            for (int j = 1; j <= 2 * n; j++) {
                cout << vec[temp1] << " ";
                temp1 = temp1 + 2;
            }
        } else {
            temp2 = temp2 + 4 * n;
            int temp3 = temp2;
            for (int j = 1; j <= 2 * n; j++) {
                cout << vec[temp3] << " ";
                temp3 = temp3 - 2;
            }
        } cout << endl;
    } return 0;
}