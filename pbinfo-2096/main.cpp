#include <bits/stdc++.h>
using namespace std;
ifstream in("xyz.in");
ofstream out("xyz.out");
int main() {
    int x, y, z;
    in >> x >> y >> z;
    out << y;
    for (int i = 1; i < x; i++) out << z;
    return 0;
}