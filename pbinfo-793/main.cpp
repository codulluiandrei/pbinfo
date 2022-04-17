#include <iostream>
using namespace std;
int main() {
    int a, b, c, p, q, r, Max;
    cin >> a >> b >> c;
    p = a * b + c;
    q = a * c + b;
    r = b * c + a;
    Max= p;
    if (q > Max) Max = q;
    if (r > Max) Max = r;
    cout << Max;
    return 0;
}
