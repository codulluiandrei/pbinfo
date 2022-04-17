#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, x , y;
    cin >> n;
    cin >> x >> y;
    if (x < y) {
        int temp = x;
        x = y;
        y = temp;
    }
    for (int i = 3; i <= n; i++) {
        cin >> a;
        if (a > x) y = x, x = a;
        else if (a > y) y = a;
    } cout << x << " " << y << endl;
    return 0;
}