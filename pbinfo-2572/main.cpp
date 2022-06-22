#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, v[1000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        if (sqrt(v[i]) == int(sqrt(v[i]))) cout << "DA" << endl;
        else cout << "NU" << endl;
    }
    return 0;
}