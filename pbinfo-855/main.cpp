#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, vec[103];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i == n / 2 + 1) vec[i] = 1;
        else vec[i] = 0;
    } for (int i = 1; i <= n / 2 + 1; i++) {
        for (int j = 1; j <= n; j++)
            cout << vec[j] << " ";
        cout << endl;
        for (int j = n / 2 + 1 - i; j <= n / 2 + 1 + i; j++) vec[j]++;
    } for (int i = 1; i <= n; i++) vec[i]--;
    for (int i = n / 2; i >= 1; i--) {
        for (int j = n / 2 + 1 - i; j <= n / 2 + 1 + i; j++) vec[j]--;
        for (int j = 1; j <= n; j++)
            cout << vec[j] <<" ";
        cout << endl;
    } return 0;
}