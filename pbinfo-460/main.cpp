#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, m, x;
    cin >> h >> m >> x;
    m = m + x;
    h = h + m / 60;
    m = m % 60;
    h = h % 24;
    cout << h << " " << m;
    return 0;
}