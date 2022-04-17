#include <iostream>
using namespace std;
int main() {
    int var, contor = 0; cin >> var;
    for (int v = 1; v <= var; ++v) {
    	int n; bool aprim = false;
        cin >> n;
        int d = 2;
        while (!aprim && d * d < n) {
            if (n % d == 0) {
                int a = d, b = n / d;
                int prim = true;
                if (a < 2) prim = false;
                if (a > 2 && a % 2 == 0) prim = false;
                for (int k = 3; k * k <= a ; k += 2)
                    if (a % k == 0) prim = false;
                if (prim) {
                    prim = true;
                    if (b < 2) prim = false;
                    if (b > 2 && b % 2 == 0) prim = false;
                    for (int k = 3; k * k <= b ; k += 2)
                        if (b % k == 0) prim = false;
                    if (prim) aprim = true;
                }
            } if (d == 2) d++;
            else d = d + 2;
        } if (aprim) contor++;    
    } cout << contor;
    return 0;
}