#include <bits/stdc++.h>
using namespace std;

ifstream in("pozitiex.in");
ofstream out("pozitiex.out");

int main() {
    int n, x, v[10001], temp = 0;
    bool test = false;
    in >> x >> n;
    for (int i = 1; i <= n; i++) {
    		in >> v[i];
        if (v[i] == x) test = true;
        if (v[i] < x) temp++;
    } if (test == false) out << "NU EXISTA";
    else out << temp + 1;
    return 0;
}