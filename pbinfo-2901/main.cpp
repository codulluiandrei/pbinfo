#include <bits/stdc++.h>
using namespace std;
ifstream in("datapal.in");
ofstream out("datapal.out");
int n, st, dr, maxs, var, sec;
bool adv;
char d[9], f[100];
int main() {
    in >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 8; j++) in >> d[j];
        adv = true;
        st = 0;
        dr = 7;
        while (st < dr && adv == true)
            if (d[st] != d[dr]) adv = false;
            else {
            st++;
            dr--;
        } if (adv == true) {
            var++;
            sec = (d[4] - '0') * 10 + d[5] - '0';
            f[sec]++;
            if (f[sec] > maxs) maxs = f[sec];
        }
    } out << var << "\n";
    for (int i = 0; i <= 99; i++) if (f[i] == maxs) out << i + 1 << " ";
    return 0;
}
