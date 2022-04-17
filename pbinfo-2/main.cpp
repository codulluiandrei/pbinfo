#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, temp, suma = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        suma = suma + temp;
    } cout << suma;
    return 0;
}