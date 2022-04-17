#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x, s, c; cin >> n;
    s = c = 0;
    for (int i = 0; i < n; --n) {
        cin >> x;
        if (x % 2 == 0) {
            s = s + x; c++;
        }
    } double MEDIE = (double)s / c;
    MEDIE = MEDIE * 100;
    MEDIE = (int)(MEDIE);
    cout << MEDIE / 100;
    return 0;
}