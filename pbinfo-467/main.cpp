#include <iostream>
using namespace std;
int main() {
    int n, u, s;
    cin >> n;
    u = n % 10;
    s = n / 100;
    cout << u * s;
    return 0;
}