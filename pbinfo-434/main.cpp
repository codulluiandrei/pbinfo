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
	int n, contor = 1; cin >> n;
    for (int i = 3; contor <= n; i++) {
        if (prim(i) && prim(i + 2)) {
        	cout << i << " " << i + 2 << "\n";
            contor++;
        }
    } return 0;
}