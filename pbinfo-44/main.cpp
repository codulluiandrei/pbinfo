#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    } int nr = 0;
    for (int i = a; i <= b; i++) {
        bool prim = 1;
        if (i < 2) prim = 0;
        if (i % 2 == 0 && i > 2) prim = 0;
        for (int j = 3; j * j <= i && prim == 1; j++)
            if (i % j == 0) prim = 0;
        if (prim == 1) nr++;
    } cout << nr;
    return 0;
}