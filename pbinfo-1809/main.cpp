#include <bits/stdc++.h>
using namespace std;
int32_t _pow(int32_t a, int32_t b) {
    if (!b) return 1;
    return _pow(a, --b) * a;
}
int main() {
    int32_t a, b;
    cin >> a >> b;
    cout << _pow(a, b);
    return 0;
}