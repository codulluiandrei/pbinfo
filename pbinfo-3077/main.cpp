#include <iostream>
using namespace std;
int main() {
    int n; long long S = 0;
    cin >> n;
    while (n > 0) {
        S = S + n;
        n = n / 10;
    } cout << S;
    return 0;
}