#include <iostream>
using namespace std;
int prim(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int d = 3; d * d <= n; d = d + 2)
        if (n % d == 0)
        	return 0;
	return 1;
}
int main() {
    int a, b, nr = 0, minim = 10000000; cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        if (prim(i))
            if (abs(b + a - 2 * i) < minim) {
                minim = abs(b + a - 2 * i);
            	nr = i;
            }
    } if (nr) cout << nr;
    else cout << "NU EXISTA";
	return 0;
}