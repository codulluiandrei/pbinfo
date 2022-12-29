#include <iostream>
using namespace std;
int main() {
    int a, b, x, y, L;
    cin >> a >> b;
    x = a, y = b;
    L = b;
    while (a % b != 0){
        L = a % b;
        a = b;
        b = L;
    } cout << x / L * y / L << " " << L;
    return 0;
}