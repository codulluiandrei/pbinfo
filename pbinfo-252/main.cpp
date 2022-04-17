#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    if (n % 2 == 1) cout << n - 4 << " " << n - 2; 
    else cout << n - 3 << " " << n - 1;
    return 0;
}