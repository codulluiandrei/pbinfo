#include <iostream>
using namespace std;
int n, k;
int main() { 
    cin >> n >> k;
    int r = 2, x, lin = 2, i;
    long long int p, ma = 0, m = 0;
    p = 3;
    for (i = 1; i <= k; i++) {  
        cin >> x;
        if (p < x) {
            if (m > ma) {
                ma = m;
                lin = r;
            } m = 1;
            while (p < x) {
                r++;
                p = p + r;
            }
        } else m++;
    } if (m > ma) {
        ma = m;
        lin = r;
    } cout << lin << endl;
    cout << 2 * (n - 1) << endl;
    return 0;
}