#include <bits/stdc++.h>
using namespace std;
int main() {
    double n; double pi = 3.14159265;
    cin >> n;
    cout << fixed << setprecision(3) << sin(n * pi / 180) << " " << cos(n * pi / 180);
    return 0;
}