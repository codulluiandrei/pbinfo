#include <iostream>
using namespace std;
int main() {
    int z, pb, b, pt, t;
    cin >> z >> pb >> b >> pt >> t;
    for (int i = 1; i <= z; i++) {
        pb = pb + b;
        pt = pt + t;
        if (pb == pt) {
            cout << pb;
            return 0;
        }
    } cout << -1;
}