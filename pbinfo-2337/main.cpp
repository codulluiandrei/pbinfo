#include <bits/stdc++.h>
using namespace std;

ifstream in("coada2.in");
ofstream out("coada2.out");

long long x, y, z;
int main() {
    in >> x >> y >> z;
    if (x >= y || x >= z) out << -1;
    else out << y + z - x;
    return 0;
}