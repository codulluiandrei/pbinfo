#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, v[50];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i + n] = v[i];
    } for (int i = n + 1; i > 1; i--) {
        for (int j = i; j < i + n; j++)
            cout << v[j] << " ";
        cout << endl;
    } return 0;
}