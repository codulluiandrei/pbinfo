#include <iostream>
using namespace std;
int main() {
    int a, b, c, d, p, q, cp, cq, r;
    cin >> a >> b >> c >> d;
    cp = p = a * d + b * c, cq = q = b * d;
    r = 1;
    while (p % q != 0){
        r = p % q;
        p = q;
        q = r;
    } cout << cp / q << " " << cq / q << endl;
    cp = p = a * c, cq = q = b * d;
    r = 1;
    while (p % q != 0){
        r = p % q;
        p = q;
        q = r;
    } cout << cp / q << " " << cq / q << endl;
    return 0;
}