#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    if (n / 100 != 0) cout << 3;
    else if (n / 100 == 0 && n / 10 != 0) cout << 2;
    else cout <<1;
    return 0; 
}