#include <bits/stdc++.h>
using namespace std;
ifstream in("magic3.in");
ofstream out("magic3.out");
int nrdiv(int n) {
    int temp = 1, d = 2;
    while(n > 1) {
        int p = 0;
        while (n % d == 0)
            p++, n = n / d;
        if (p != 0) temp = temp * (p + 1);
        d++;
        if (d * d > n) d = n;
    } return temp;
} int main() {
    int n, v[1005], var = 0, minim = 1000000000;
    in >> n;
    for (int i = 1; i <= n; i++) {
        in >> v[i];
        if (nrdiv(v[i]) < minim) minim = nrdiv(v[i]);
    } for (int i = 1; i <= n; i++) {
        if (nrdiv(v[i]) == minim)
            var++;
    } out << var;
    return 0;
}