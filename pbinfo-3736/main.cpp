#include <bits/stdc++.h>
using namespace std;
ifstream in ("sir.in");
ofstream out("sir.out");
int n, C, maxim = 0, temp, val, rez;
int main () {
    in >> C >> n;
    if (C == 1) {
        for (int i = 1; i <= n; i++) {
            in >> temp;
            if (temp >= maxim) {
                maxim = temp;
                val = i;
            }
        } out << val << '\n';
    } else if (C == 2) {
        for (int i = 1; i <= n; i++) {
           	in >> temp;
            if (temp > maxim) {
                maxim = temp;
                val++;
                if (val == 1) out << i;
                else out << " " << i;
            }
        } out << '\n';
    } else if (C == 3) {
        for (int i = 1; i <= n; i++) {
            in >> temp;
            if (temp > maxim) {
                maxim = temp;
                val = 0;
            } else val = val + (maxim - temp);
            if (temp == maxim) rez = val;
        } out << rez << '\n';
    } return 0;
}
