#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int n, d1, d2;
    cin >> n;
    for (d1 = 2; d1 * d1 <= n; ++d1)
        if (n % d1 == 0) break;
    if (n % d1 != 0) cout << "prim\n";
    else if (d1 * d1 == n) cout << "patrat prim\n";
	else { d2 = d1;
        for (d2 = d1; d2 * d2 <= n / d1; ++d2)
            if ((n / d1) % d2 == 0) break;
            if ((n / d1) % d2 == 0) cout << "compus\n";
            else cout << "aproape prim\n";
    } return 0;
}