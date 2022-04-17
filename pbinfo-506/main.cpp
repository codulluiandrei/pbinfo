#include <iostream>
using namespace std;
int main() {
    int n, x[1005];
    cin  >> n;  
    for (int i = 0; i < n; i++) cin >> x[i];
    bool adv = false;
    for (int i = 0; i < n && !adv; i++) {
        bool prim = true;
        if (x[i] < 2)
            prim = false;
        if (x[i] % 2 == 0 && x[i] > 2)
            prim = false;
        for (int d = 3 ; d * d <= x[i] ; d = d + 2)
            if (x[i] % d == 0) prim = false;
        if (prim == true) adv = true;
    } if(adv == true) cout << "DA";
    else cout << "NU";
    return 0;
}