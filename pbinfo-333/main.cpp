#include <bits/stdc++.h>
using namespace std;
int main() {
    float a, b, c;
    cin >> a >> b >> c;
    if (a <= 0 || b <= 0 || c <= 0 || a >= b + c || b >= a + c || c >= a + b) cout << "nu este triunghi";
    else if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b) cout << "triunghi dreptunghic";
    else if (a * a + b * b > c * c && b * b + c * c > a * a && c * c + a * a > b * b) cout << "triunghi ascutitunghic";
    else cout << "triunghi obtuzunghic";
    return 0;
}