#include <bits/stdc++.h>
using namespace std;
ifstream in("bacterie.in");
ofstream out("bacterie.out");
long long n, m, minim, inf;
int main() {
    in >> n >> m;
    minim = n;
    if (m < minim) 
        minim = m;
    inf = minim * (minim + 1) / 2;
    out << n * m - inf << '\n';
    return 0;
}
