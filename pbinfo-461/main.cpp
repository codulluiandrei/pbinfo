#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, m, x, y ;
    cin >> h >> m >> x >> y;
    m = m + x * 60 + y;
    h = h + m / 60;
    m = m % 60;
    h = h % 24;
    cout << h << " " << m;
    return 0;
}