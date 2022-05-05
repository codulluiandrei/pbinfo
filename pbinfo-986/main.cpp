#include <bits/stdc++.h>
using namespace std;
int main() {
    double v[2001], C = 0, temp1, temp2;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    temp1 = v[1];
    temp2 = v[n];
    if (temp2 < temp1) swap(temp1, temp2);
    for (int i = 1; i <= n; i++)
        if (v[i] > temp2 || v[i] < temp1) C++;
    cout << C; return 0;
}