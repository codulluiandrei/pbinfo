#include <bits/stdc++.h>
using namespace std;
int main () {
    int a, b;
    cin >> a >> b; 
    if ((a - (b * (b - 1) / 2)) % b == 0)
        cout << "DA";
    else 
        cout << "NU";
    return 0;
}