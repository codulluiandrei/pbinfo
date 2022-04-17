#include <bits/stdc++.h>
using namespace std;
ifstream in("fantastice.in");
ofstream out("fantastice.out");
int prim(int n) {
    if (n == 0 || n == 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    else for(int d = 3; d * d <= n; d = d + 2) 
        if (n % d == 0) 
            return 0;
    return 1;
} int nrdiv(int n) {
    int rez = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) rez = rez + 2;
        if (i * i == n) rez--;
    } if (prim(rez)) return 1;
    else return 0;
} int main() {
    int n, var, temp = 0;
    in >> n;
    for (int i = 0; i < n; i++) {
        in >> var;
        if (nrdiv(var)) temp++;
    } out << temp;
    return 0;
}