#include <iostream>
using namespace std;
int main() {
    int n, a, b, maxima = 0, maximb = 0, temp = -1;
    cin >> n;
    for (int i = 1; i <= n; --n) {
        cin >> a >> b;
        int x = a, y = b;
        while (y) {
            int r = x % y;
            x= y;
            y = r;
        } if (x > temp) temp = x, maxima = a, maximb = b;
        else if (x == temp) if(a + b > maxima + maximb) maxima= a, maximb = b;
    } cout << maxima << " " << maximb;
    return 0;
}