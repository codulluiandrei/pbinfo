#include <bits/stdc++.h>
using namespace std;
ifstream in("permutari2.in");
ofstream out("permutari2.out");
int n, x[10], nr[10];
bool f[10];
void afisare() {
    for (int i = 1; i <= n; i++)
        out << nr[x[i]] << " ";
    out << '\n';
}
void back(int k) {
    for (int i = 1; i <= n; i++)
        if (f[i] == false) {
            x[k] = i;
            f[i] = true;
            if (k == n) afisare();
            else back(k + 1);
            f[i] = false;
        }
}
int main() {
    in >> n;
    for (int i = 1; i <= n; i++)
        in >> nr[i];
    sort(nr + 1, nr + n + 1);
    back(1);
    return 0;
}