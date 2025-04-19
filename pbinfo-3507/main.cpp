#include <bits/stdc++.h>
using namespace std;
ifstream f ("fibo_gcd.in");
ofstream g ("fibo_gcd.out");
int n, x, y, cnt, D;
int main() {
    f >> n;
    while (n --) {
        f >> x >> y;
        D = __gcd (x, y);
        if (D == 1 || D == 2) cnt ++;
    }
    g << cnt << '\n';
    f.close();
    g.close();
    return 0;
}