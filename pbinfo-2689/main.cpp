#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, v[1001];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i], cout << v[i];
    for (int i = 1, j = n; i < j; i++, j--)
        if (v[i] != v[j]) {
        cout << endl << "NU";
        return 0;
    } cout << endl << "DA";
    return 0;
}