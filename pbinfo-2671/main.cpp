#include <iostream>
using namespace std;
int main() {
    int n, m, e, b, E, B;
    cin >> n >> m >> e >> b;
    B = (m * b + e) / (m - n);
    E = n * B + e;
    cout << E << "\n" << B;
}