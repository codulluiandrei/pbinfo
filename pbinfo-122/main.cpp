#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, cn, cm;
    cin >> n >> m;
    int rn = 0, rm = 0;
    cn = n, cm = m;
    while (cn) rn = rn + cn % 2, cn = cn / 2;
    while (cm) rm = rm + cm % 2, cm = cm / 2;
    if (rn > rm) cout << n;
    else if (rm > rn)cout << m;
        else cout << (n < m ? n : m);
    return 0;
}