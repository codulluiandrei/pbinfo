#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, v1, v2, temp, S = 0; cin >> n >> v1 >> v2;
    for (int i = 3 ; i <= n; i++) {
        cin >> temp;
        if (v1 < v2 && v2 > temp)
            S = S + v2;
        v1 = v2;
        v2 = temp;
    } cout << S;
    return 0;
}