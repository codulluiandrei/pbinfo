#include <iostream>
using namespace std;
int main() {
    int n, k, p;
    cin >> n >> k;
    p = 0;
    while (n > 1) {
        p++;
        n = n / 10;
    } cout << "1";
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= p; j++)
            cout << "0";
    return 0;
}