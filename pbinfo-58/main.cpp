#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, r; cin >> a >> b;
    if ( b!= 0)
        do {
            r = a % b;
            a = b;
            b = r;
        } while (r);
    else if (a == 0) a = -1;
    cout << a << endl;
    return 0;
}