#include <iostream>
using namespace std;
int main() {
    int n, x, P = -1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x % 2 == 0)
            if (P == -1) P = x;  
    } if (P != -1) cout << P;
    else cout << "IMPOSIBIL";
    return 0;
}