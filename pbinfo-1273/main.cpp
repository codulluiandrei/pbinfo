#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, suma;
    cin >> x >> y;
    suma = x % 10 + y % 10;
    suma = suma % 10;
    cout << suma;
}