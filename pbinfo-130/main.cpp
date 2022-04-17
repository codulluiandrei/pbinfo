#include <bits/stdc++.h>
using namespace std;
ifstream in("sortcif.in");
ofstream out("sortcif.out");
int n, v[105];
int sumacifre(int n) {
    int S = 0;
    while (n != 0) {
        S = S + n % 10;
    	n = n / 10;
    } return S;
} bool sortarecifre(int nr1, int nr2) {
    return sumacifre(nr1) < sumacifre(nr2);
} int main() {
    in >> n;
    for (int i = 0; i < n; i++) in >> v[i];
    sort(v, v + n, sortarecifre);
    for (int i = 0; i < n; i++) out << v[i] << " ";
    return 0;
}