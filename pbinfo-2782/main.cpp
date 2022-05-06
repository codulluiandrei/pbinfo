#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int a, b, d;
    cin >> a >> b >> d;
    if (a < b) a = a ^ b, b = b ^ a, a = a ^ b;
    cout << abs((b * b + d * d - a * a) / (2 * d));
}