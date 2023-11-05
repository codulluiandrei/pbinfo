#include <bits/stdc++.h>
using namespace std;
int main() {
    int nr1, nr2, nr3;
    cin >> nr1 >> nr2 >> nr3;
    if (nr1 != nr2 && nr2 != nr3 && nr1 != nr3) cout << 3;
    else if (nr1 == nr2 && nr2 == nr3) cout << 1;
    else cout << 2;
    return 0;
}