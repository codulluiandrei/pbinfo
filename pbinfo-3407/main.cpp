#include <bits/stdc++.h>
using namespace std;
ifstream in("aoc2020.in");
ofstream out("aoc2020.out");
#define cin in
#define cout out
int main() {
    int n;
    long long rez, temp, a, b;
    cin >> n >> rez;
    for (int i = 2; i <= n; i++) {
        cin >> temp;
        a = rez; b = temp;
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        } rez = rez / a * temp;
    } cout << rez;
    return 0;
}