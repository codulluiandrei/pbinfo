#include <bits/stdc++.h>
using namespace std;
int main() {
    int suma = 0, temp =-1;
    while (temp) {
    cin >> temp;
    if (temp % 2 == 1)
    suma++;
    } cout << suma;
    return 0;
}