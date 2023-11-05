#include <bits/stdc++.h>
using namespace std;
long long n, m, minim, inf;
int main() {
    cin >> n >> m;
    minim = n;
    if (m < minim) 
        minim = m;
    inf = minim * (minim + 1) / 2;
    cout << n * m - inf << '\n';
    return 0;
}