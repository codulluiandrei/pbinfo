#include <iostream>
using namespace std;
int main() {
    int a, n, minim = 9999999999;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a < minim) {
            minim = a;
        }
    } cout << minim;
    return 0;
}
