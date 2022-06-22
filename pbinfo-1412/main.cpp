#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, c;
    cin >> c >> n;
    if (c == 1)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
        cout << i;
        cout << endl;
    } if (c == 3)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n*2; j++)
        cout << i;
        cout << endl;
    } if (c == 2) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++)
            cout << " ";            
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << i;
        cout << '\n';
    } for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++)
            cout << " ";
        for (int j = 1; j <= 2 * (n - i) - 1; j++)
            cout << n - i;
        cout << '\n';
    } } if (c == 4)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << i;
        cout << '\n';
    } return 0;  
}