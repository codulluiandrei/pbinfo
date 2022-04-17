#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, C, m = 1;
    cin >> n >> C;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        if (s + v <= C) s = s + v;
        else {
            m ++;
            s = v;
        }
    } cout << m;
    return 0;
}