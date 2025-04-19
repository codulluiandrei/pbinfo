#include <fstream>
using namespace std;
ifstream in("clase.in");
ofstream out("clase.out");
long long int cb(long long int x);
long long int v[10001];
long long int n, m, pachet, test, contor;
int main() {
    in >> n;
    for (int i = 1; i <= n; ++i)
        in >> v[i];
    in >> m;
    for (int i = 1; i <= m; ++i) {
        in >> pachet;
        test = cb(pachet);
        if (test != -1) ++contor;
    } out << contor;
    return 0;
}
long long int cb(long long x) {
    long long test = -1, stanga = 0, dreapta = n;
    while (stanga <= dreapta) {
        int Mid = (stanga + dreapta) / 2;
        if (v[Mid] == x) { test = Mid; break; }
        if (v[Mid] > x) dreapta = Mid - 1;
        if (v[Mid] < x) stanga = Mid + 1;
    } return test;
}