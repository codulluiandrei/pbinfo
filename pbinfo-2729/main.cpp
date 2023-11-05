#include <iostream>
using namespace std;
long long int n, rn, rm, x, y, v, minim = -1;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        rm = rm + x;
        rn = rn + y;
    } cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> v;
        if (x >= rn && y >= rm) {
            if (minim == -1) 
                minim = v;
            else minim = min(minim, v);
        }
    } cout << minim;
    return 0;
}