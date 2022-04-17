#include <iostream>
using namespace std;
int main() {
    int a, b, x;
    cin >> a >> b >> x;
    if (x >= a && x <= b) cout << "DA";
    else cout << "NU";
    return 0;
}