#include <bits/stdc++.h>
using namespace std;
int main() {
    long double r, A, V;
    long long int a, v;
    cin >> r;
    A = 4 * 3.141592653589 * r * r;
    V = 4 * 3.141592653589 * r * r * r / 3;
    a = A * 100;
    v = V * 100;
    cout << a / 100 << "." << a / 10 % 10 << a % 10 << " " << v / 100 << "." << v / 10 % 10 << v % 10;
    return 0;
}