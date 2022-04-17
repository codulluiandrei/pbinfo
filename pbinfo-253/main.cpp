#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    if (n % 2 == 1) cout << n + 1 << " " << n + 3; 
    else cout << n + 2 << " " << n + 4; 
    return 0;
}