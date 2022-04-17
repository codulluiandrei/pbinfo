#include <bits/stdc++.h>
using namespace std;
ifstream in("tort.in");
ofstream out("tort.out");
int cmmdc(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    } return a;
} int main() {
    int n, m;
    in >> n >> m;
    int prod = n * m;
    int cm = cmmdc(n, m);
    out << prod / (cm * cm) << " " << cm;
    return 0;
}