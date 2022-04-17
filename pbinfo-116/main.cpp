#include <iostream>
#include <iomanip>
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
	int n, contor = 0, sum = 0; cin >> n;
    for (int i = 1; i <= n; ++i) {
    	int temp; cin >> temp;
        if (prim(temp)) sum = sum + temp, contor++;
    } cout << fixed << setprecision(2) << (double) ((sum * 100) / contor) * 0.01;
    return 0;
}