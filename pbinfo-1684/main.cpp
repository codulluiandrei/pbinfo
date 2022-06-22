#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int suma = 0;
    for (int i = 1; i <= n ; ++i) {
        suma = suma + i * i;
        cout << suma << " ";
    } return 0;    
}