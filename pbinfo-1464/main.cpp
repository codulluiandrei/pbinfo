#include <iostream>
using namespace std;
int main() {
    int P, K;
    cin >> P >> K;
    if (K % 2 == 1) cout << K + K / 2 - 1 << P;
    else cout << K + K / 2 - 2 << P;
    return 0;
}