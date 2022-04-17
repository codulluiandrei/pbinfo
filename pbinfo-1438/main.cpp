#include <bits/stdc++.h>
using namespace std;

ifstream in("razboi.in");
ofstream out("razboi.out");

int sumadivi(int n) {
    int S = 0;
    for(int i = 1; i * i <= n; i++) {
        if (i * i == n) S = S - i;
        if (n % i == 0) S = S + i + n / i;
    } return S;
}
int main() {
    int n, L;
    in >> n >> L;
    if (L == 1) {
        int nr, temp = 0;
        for (int i = 0; i < n; i++) {
            in >> nr;
            if (nr % 2 == 0) temp++;
        } out << temp << " " << n - temp;
    } if (L == 2) {
        int nr, temp = 0;
        for (int i = 0; i < n; i++) {
            in >> nr;
            if (sumadivi(nr) % 2 == 0) temp++;
        } out << temp << " " << n - temp;
    } return 0;    
}