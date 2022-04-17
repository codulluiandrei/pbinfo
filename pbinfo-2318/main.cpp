#include <bits/stdc++.h>
using namespace std;

ifstream in("conversie_b_10.in");
ofstream out("conversie_b_10.out");

int main() {
    int n, b, nr = 1, v[10], temp = 0; in >> n >> b;
    while (n != 0) {
        v[temp] = n % 10;
        n = n /10;
        temp++;
    } nr = v[temp - 1];
    for (int i = temp - 2; i >= 0; i--) nr = nr * b + v[i];    
    out << nr;
    return 0;
}