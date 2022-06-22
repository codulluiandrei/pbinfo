#include <bits/stdc++.h>
using namespace std;
long long int a, b, c, Ka, Kb;
int nr;
int main() {
    cin >> Ka >> Kb;
    for (nr = 0, a = 1, b = 1; Ka >= b / 2 + b % 2 && Kb >= b / 2; nr++) {
        Ka -= b / 2 + b % 2;
        Kb -= b / 2;
        c = a + b;
        a = b;
        b = c;
    } cout << nr << "\n" << Ka << "\n" << Kb;
    return 0;
}