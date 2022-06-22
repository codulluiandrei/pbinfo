#include <bits/stdc++.h>
using namespace std;
ifstream in("sumagauss2.in");
ofstream out("sumagauss2.out");
int main() {
    long long S1, n, m, temp, i;
    in >> S1; S1 = S1 * 2;
    for (i = 1; i * i <= S1; i++) {
        if (S1 % i == 0) {
            temp = i + S1 / i - 1;
            if (temp % 2 == 0) {
                n = temp / 2;
                m = n - i;
                out << n << " " << m <<endl;;
            }
        }
    } return 0;
}