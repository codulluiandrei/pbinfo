#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, u, s;
    cin >> n;
    u = n % 10;
    s = n / 100;
    int  p = s * 10 + u; 
    cout << p * p;
    return 0;
}