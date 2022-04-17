#include <bits/stdc++.h>
using namespace std;
int main() {
    int G, O, P, C;
    cin >> C >> P;
    O = (P - 2 * C) / 2;
    G = C - O;
    cout << G << " " << O ;
    return 0;
}