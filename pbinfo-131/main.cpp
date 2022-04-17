#include <bits/stdc++.h>
using namespace std;
ifstream in("sortcif2.in");
ofstream out("sortcif2.out");
int n, v[105];
int veirfprime(int n) {
    while (n > 9) n = n / 10;
    return n;
} bool sortarecifre(int a, int b) {
	return veirfprime(a) < veirfprime(b);
} int main() {
    in >> n;
    for (int i = 0; i < n; i++) in >> v[i];
    sort(v, v + n, sortarecifre);
    for (int i = 0; i < n; i++) out << v[i] << " ";
    return 0;
}