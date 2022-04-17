#include <iostream>
using namespace std;
int main() {
    int n, a, b;
    cin >> a >> b >> n;
    if (a <= n && n <= b) cout << "DA";
    else cout << "NU";
    return 0;
}