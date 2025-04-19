#include <iostream>
using namespace std;
int main() {
    long long int n, x, minim = 10;
    cin >> n >> x;
    while (n != 0) {
        int c = n % 10;
        n = n / 10;
        if (c < minim && c > x)
            minim = c;
    } if (minim == 10)
        cout << -1;
    else cout << minim;
    return 0;
}