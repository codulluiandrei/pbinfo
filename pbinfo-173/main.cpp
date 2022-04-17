#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, z;
    float medie;
    cin >> x >> y >> z;
    medie = (x + y + z) / 3.;
    medie = (int) (medie * 100) / 100.;
    cout << fixed << setprecision(2) <<  medie;
    return 0;
}