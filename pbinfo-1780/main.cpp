#include <iostream>
using namespace std;
int aflare(int i, int m) {
    int x = 0;
    while (i % m == 0) {
        i = i / m;
        x++;
    } return x;
}
int main() {
    int n, m, x = 0;
    cin >> n >> m;
    if (n == 0 && m == 1) cout << 1;
    else {
        for (int i = 1; i <= n; i++)
            x = x + aflare(i, m);
        cout << x;
    } return 0;
}