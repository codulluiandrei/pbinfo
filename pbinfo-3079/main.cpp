#include <iostream>
using namespace std;
int main() {
    int a, b, c = 0, v = 1, temp;
    cin >> a >> b;
    while (a > 0) {
        temp = (a % 10 + b % 10) / 2;
        a = a / 10; b = b / 10;
        c = c + temp * v;
        v = v * 10;
    } cout << c;
    return 0;
}