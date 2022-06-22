#include <iostream>
using namespace std;
int cif1(int nr) {
    while (nr > 9) nr = nr / 10;
    return nr;
}
int main() {
    int n, x, y;
    cin >> n;
    cin >> x;
    for (int i = 2; i <= n; i++) {
        cin >> y;
        if (x % 10 == cif1(y))
            cout << x << " " << y << endl;
        x = y;
    } return 0;
}