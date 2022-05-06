#include <iostream>
using namespace std;
int main() {
    int n, a = 10, b = -1;
    cin >> n;
    do {
        if (n % 10 > b) b = n % 10;
        if (n % 10 < a) a = n % 10;
        n = n / 10;
    } while (n);
    cout << a + b;
    return 0;
}