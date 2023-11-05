#include <iostream>
using namespace std;
int nrcif(int x) {
    if (x <= 9) return 1;
    if (x <= 99) return 2;
    if (x <= 999) return 3;
    if (x <= 9999) return 4;
    if (x <= 99999) return 5;
    if (x <= 999999) return 6;
    return -1;
}
int main() {
    int n;
    cin >> n;
    cout << n;
    for (int i = nrcif(n); i < n; ++i)
        cout << 0;
    return 0;
}