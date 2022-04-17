#include <bits/stdc++.h>
using namespace std;
int main() {
    int suma = 0, temp =-1;
    while (temp) {
    cin >> temp;
    if (temp % 2 == 0)
    suma = suma + temp;
    } cout << suma;
    return 0;
}