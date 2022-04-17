#include <iostream>
using namespace std;
int main() {
    long long n, k;
    cin >> n >> k;
    int i = 1, j = 1;
    while (i <= n) {
        cout << "1";
        i++;
    } cout << "01";
    while (j <= k) {
        cout << "0";
        j++;
    } cout << "10";
    return 0;
}