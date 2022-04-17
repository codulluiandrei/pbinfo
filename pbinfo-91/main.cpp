#include <bits/stdc++.h>
using namespace std;

ifstream in("masini.in");
ofstream out("masini.out");

int n, v[1001], t, suma, k;

int main() {
    in >> n >> t;
    for (int i = 0; i < n; i++) in >> v[i];

    sort(v, v + n);

    for (int i = 0; i < n; i++) {
        if (suma + v[i] <= t) {
        	suma = suma + v[i];
        	k++;
        }
    } out << k;
    return 0;
}