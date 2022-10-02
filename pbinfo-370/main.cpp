#include <iostream>
using namespace std;
bool sum(int n, int k) {
    int sumcif = 0;
    while (n > 0) {
        sumcif = sumcif + n % 10;
        n = n / 10;
    } if (sumcif % k == 0)
        return true;
    return false;
}
int main() {
    int n, k, S = 0;
    cin >> k >> n;
    for (int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        if (sum(temp, k) == true)
            S = S + temp;
    } cout << S;
    return 0;
}