#include <iostream>
using namespace std;
int main() {
    int n, a, b, c;
    cin >> n;
    a = n % 10;
    b = n / 10 % 10;
    c = n / 100;
    cout << 222 * (a + b + c);
    return 0;
}