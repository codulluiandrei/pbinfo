#include <iostream>
using namespace std;
int main() {
    int n;
    bool prim = false;
    cin >> n;
    while (!prim) {
        n++;
        prim = true;
        if (n < 2) prim = false;
        if (n % 2 == 0 && n > 2) prim = false;
        for (int d = 3; d * d <= n; d = d + 2)
            if (n % d == 0) prim = false;
    } cout << n;
    return 0;
}