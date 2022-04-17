#include <iostream>
using namespace std;
int main() {
    int n, nr = 0, i = 1;
    cin >> n;
    while (i <= n) {
        if (n % i == 0 && i > 1) {
            nr = i;
            break;
        } i++;
    } cout << nr * nr;
    return 0;
}
