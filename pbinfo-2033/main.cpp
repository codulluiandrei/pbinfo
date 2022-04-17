#include <bits/stdc++.h>
using namespace std;
ifstream in("mcub.in");
ofstream out("mcub.out");
int n, inal[100001];
long long rez;
int main() {
    in >> n;
    for (int i = 1; i <= n; i++) {
        in >> inal[i];
        if (inal[i] > inal[i - 1])
            rez = rez + inal[i] - inal[i - 1];
    } out << rez << '\n';
    return 0;
}