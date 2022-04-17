#include <bits/stdc++.h>
using namespace std;

ifstream in("maxcadou.in");
ofstream out("maxcadou.out");

int main() {
    long long int n, temp;
    int nrcif = 0, mmz = 0, v[11];
    in >> n; temp = n;
    if (n == 0) {
        out << 0;
        return 0;
    } else if (n < 10) {
    	out << n;
        return 0;
    }
    else mmz = 1;
    while (temp != 0) {
        nrcif++;
        temp = temp / 10;
    }
    for (int i = 0; i < nrcif; i++) {
        v[i] = n % 10;
        n = n / 10;
    }
    sort(v + 0, v + nrcif + 1, greater<int>());
    if (mmz == 1) {
        for (int i = 0; i < nrcif; i++) {
            out << v[i];
        }
    } return 0;
}