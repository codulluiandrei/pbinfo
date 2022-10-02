#include <bits/stdc++.h>
using namespace std;
ifstream in("cifre15.in");
ofstream out("cifre15.out");
int main() {
    int n, nr2 = 0, nr5 = 0, p = 1;
    in >> n;
    for (int i = 1; i <= n; ++i) {
        int temp;
        in >> temp;
        while (temp % 2 == 0) {
            nr2++;
            temp = temp / 2;
        } while (temp % 5 == 0) {
            nr5++;
            temp = temp / 5;
        } p = (p * (temp % 10)) % 10;
    } out << min(nr2, nr5) << " ";
    int c = 0, z = 0;
    if (nr2 > nr5) {
        c = nr2 - nr5;
        z = 2;
    } else {
        c = nr5 - nr2;
        z = 5;
    } while (c > 0) {
        p = (p * z) % 10;
        c--;
    } out << p;
    return 0;
}