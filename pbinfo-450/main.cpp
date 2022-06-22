#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, operatie;
    cin >> a >> b >> operatie;
    if (operatie == 1) { cout << a + b; } 
    if (operatie == 2) { cout << a - b; }
    if (operatie == 3) { cout << a * b; }
    if (operatie == 4) { cout << a / b; }
    if (operatie == 5) { cout << a % b; }
    return 0; 
}