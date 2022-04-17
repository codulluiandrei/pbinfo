#include <iostream>
using namespace std;
int main() {
    int n, r, val = 0;
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        if (x % 9 == r) val++;
    } cout << val;
    return 0;
}