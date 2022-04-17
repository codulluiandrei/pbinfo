#include <bits/stdc++.h>
using namespace std;
string problema = "maxprimeintreele";
ifstream in(problema + ".in");
ofstream out(problema + ".out");
#define cin in
#define cout out
int phi(int x) {
    int d, e = x;
    if (x % 2 == 0) {
        e = e - e / 2;
        while (x % 2 == 0) x = x /2;
    } for (int d = 3; d * d <= x; d = d + 2)
        if (x % d == 0) {
            e = e - e / d;
            while (x % d == 0) x = x / d;
    } if (x > 1) e = e - e / x;
    return e;
} int main() {
    int x, y;
    float maxim = 0;
    while (cin >> x) {
        float temp = (float)x / phi(x);
        if (temp > maxim) {
            maxim = temp;
            y = x;
        }
    } cout << y;
    return 0;
}